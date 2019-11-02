# $FreeBSD$

PORTNAME=	urbackup-server
DISTVERSION=	2.4.11
CATEGORIES=	archivers
MASTER_SITES=	https://hndl.urbackup.org/Server/${DISTVERSION}/

MAINTAINER=	freebsd@coombscloud.com
COMMENT=	Server component of the UrBackup backup system

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/server-license.txt

LIB_DEPENDS=	libcryptopp.so:security/cryptopp \
		libcurl.so:ftp/curl \
		liblmdb.so:databases/lmdb

USES=		autoreconf compiler:c++11-lang dos2unix fakeroot fuse \
		libtool lua:53+ pkgconfig sqlite:3
USE_RC_SUBR=	urbackup_server

USERS=		urbackup
GROUPS=		urbackup

DOS2UNIX_GLOB=	*.c *.cpp *.h *.am
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-packaging --with-mountvhd --without-embedded-sqlite3 --without-embedded-lmdb --without-embedded-lua
CXXFLAGS+=	`pkgconf --cflags-only-other libcryptopp`
LDFLAGS+=	-L${LOCALBASE}/lib

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

	@(cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|/etc/urbackup|${PREFIX}/etc/urbackup|g' \
		mount_helper/main.cpp \
		urbackupserver/server.cpp \
		urbackupserver/serverinterface/settings.cpp \
		urbackupserver/dllmain.cpp \
		snapshot_helper/main.cpp \
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
