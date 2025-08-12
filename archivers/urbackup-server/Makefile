PORTNAME=	urbackup-server
DISTVERSION=	2.5.33
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	https://hndl.urbackup.org/Server/${DISTVERSION}/

MAINTAINER=	ek@purplehat.org
COMMENT=	Server component of the UrBackup backup system
WWW=		https://www.urbackup.org

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/server-license.txt

LIB_DEPENDS=	libcryptopp.so:security/cryptopp \
		libcurl.so:ftp/curl \
		liblmdb.so:databases/lmdb \
		libzstd.so:archivers/zstd

USES=		autoreconf compiler:c++11-lang dos2unix fakeroot fuse libtool \
		lua:53 localbase pkgconfig sqlite:3
DOS2UNIX_GLOB=	*.am *.c *.cpp *.h
USE_CXXSTD=	c++14
USE_RC_SUBR=	urbackup_server

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-packaging \
		--with-mountvhd \
		--without-embedded-lmdb \
		--without-embedded-lua \
		--without-embedded-sqlite3

.include <bsd.port.options.mk>

# Fix segmentation fault, PR 266531
# see also 5a19c08: security/cryptopp: Update to 8.7.0
.if ${ARCH} == i386 || ${ARCH} == amd64
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM
.endif

SUB_FILES=	pkg-message urbackupsrv.conf.sample-daemon

USERS=		urbackup
GROUPS=		urbackup

post-patch:
	(cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|/etc/urbackup|${PREFIX}/etc/urbackup|g' \
		mount_helper/main.cpp \
		urbackupserver/server.cpp \
		urbackupserver/serverinterface/settings.cpp \
		urbackupserver/dllmain.cpp \
		snapshot_helper/main.cpp \
	)
	${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} \
		-e 's|std::char_traits|std::vector|g' \
		-e 's|std::basic_string|std::vector|g' \
		-e 's|auto_ptr|unique_ptr|g' {} +

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/urbackup \
		 ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${WRKDIR}/urbackupsrv.conf.sample-daemon \
		${STAGEDIR}${PREFIX}/etc/urbackup/urbackupsrv.conf.sample
	${INSTALL_DATA} ${FILESDIR}/urbackupsrv.conf-newsyslog \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/urbackupsrv.conf

	${INSTALL_MAN} ${WRKSRC}/docs/urbackupsrv.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
