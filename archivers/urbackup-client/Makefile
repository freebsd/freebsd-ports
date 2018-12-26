# $FreeBSD$

PORTNAME=	urbackup-client
DISTVERSION=	2.2.6
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	https://hndl.urbackup.org/Client/${DISTVERSION}/

MAINTAINER=	freebsd@coombscloud.com
COMMENT=	Client component of the UrBackup backup system

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcryptopp.so:security/cryptopp

USES=		autoreconf compiler:c++11-lang dos2unix gettext localbase \
		pkgconfig
USE_RC_SUBR=	urbackup_client

USERS=		urbackup
GROUPS=		urbackup

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-clientupdate
CXXFLAGS+=	`pkgconf --cflags-only-other libcryptopp`

SUB_FILES=	pkg-message urbackupclient.conf.sample-daemon

WRKSRC=		${WRKDIR}/${DISTNAME}.0

OPTIONS_DEFINE=	GUI
OPTIONS_SUB=	yes

GUI_DESC=		GTK2 Tray Icon
GUI_USE=		WX=3.0+
GUI_CONFIGURE_ON=	--with-wx-config=${WX_CONFIG}
GUI_CONFIGURE_OFF=	--enable-headless

CONFFILES=	mariadbdump.conf \
		mariadbxtrabackup.conf \
		postgresbase.conf \
		postgresqldump.conf

post-patch:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} -E -e 's|[[:<:]]byte[[:>:]]|CryptoPP::byte|g' \
		cryptoplugin/AESDecryption.cpp \
		cryptoplugin/AESEncryption.cpp \
		cryptoplugin/AESGCMDecryption.cpp \
		cryptoplugin/AESGCMEncryption.cpp \
		cryptoplugin/CryptoFactory.cpp \
		cryptoplugin/ECDHKeyExchange.cpp \
		cryptoplugin/ZlibCompression.cpp \
		cryptoplugin/ZlibDecompression.cpp \
		md5.h \
	)

post-stage:
	${INSTALL_DATA} ${WRKDIR}/urbackupclient.conf.sample-daemon \
		${STAGEDIR}${PREFIX}/etc/urbackup/urbackupclient.conf.sample

	${INSTALL_DATA} ${FILESDIR}/urbackupclient.conf-newsyslog \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/urbackupclient.conf

	${INSTALL_MAN} ${WRKSRC}/docs/urbackupclientbackend.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.for f in ${CONFFILES}
	${MV} ${STAGEDIR}${PREFIX}/etc/urbackup/${f} ${STAGEDIR}${PREFIX}/etc/urbackup/${f}.sample
.endfor

	${RM} ${STAGEDIR}/var/urbackup/version.txt
	${RM} ${STAGEDIR}${PREFIX}/share/urbackup/urbackup_ecdsa409k1.pub

.include <bsd.port.mk>
