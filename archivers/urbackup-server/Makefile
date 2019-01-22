# $FreeBSD$

PORTNAME=	urbackup-server
DISTVERSION=	2.2.11
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	https://hndl.urbackup.org/Server/${DISTVERSION}/

MAINTAINER=	freebsd@coombscloud.com
COMMENT=	Server component of the UrBackup backup system

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/server-license.txt

LIB_DEPENDS=	libcryptopp.so:security/cryptopp \
		libcurl.so:ftp/curl

USES=		compiler:c++11-lang fakeroot pkgconfig
USE_RC_SUBR=	urbackup_server

USERS=		urbackup
GROUPS=		urbackup

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-packaging
CXXFLAGS+=	`pkgconf --cflags-only-other libcryptopp`

SUB_FILES=	pkg-message urbackupsrv.conf.sample-daemon

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

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/urbackup
	${INSTALL_DATA} ${WRKDIR}/urbackupsrv.conf.sample-daemon \
		${STAGEDIR}${PREFIX}/etc/urbackup/urbackupsrv.conf.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/urbackupsrv.conf-newsyslog \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/urbackupsrv.conf

	${INSTALL_MAN} ${WRKSRC}/docs/urbackupsrv.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
