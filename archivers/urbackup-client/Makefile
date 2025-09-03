PORTNAME=	urbackup-client
DISTVERSION=	2.5.26.0
CATEGORIES=	archivers
MASTER_SITES=	https://hndl.urbackup.org/Client/${DISTVERSION:R}/

MAINTAINER=	ek@purplehat.org
COMMENT=	Client component of the UrBackup backup system
WWW=		https://www.urbackup.org

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcryptopp.so:security/cryptopp \
		libzstd.so:archivers/zstd

USES=		autoreconf dos2unix libtool localbase pkgconfig sqlite:3 ssl
USE_CXXSTD=	c++14
USE_RC_SUBR=	urbackup_client

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-clientupdate \
		--enable-headless \
		--without-embedded-sqlite3

EXTRA_PATCHES=	${.CURDIR}/../urbackup-server/files/patch-fileservplugin_FileMetadataPipe.cpp \
		${.CURDIR}/../urbackup-server/files/patch-fsimageplugin_CompressedFile.cpp
SUB_FILES=	pkg-message urbackupclient.conf.sample-daemon

USERS=		urbackup
GROUPS=		urbackup

CONFFILES=	mariadbdump.conf mariadbxtrabackup.conf postgresbase.conf \
		postgresqldump.conf

.include <bsd.port.options.mk>

# Fix segmentation fault, PR 266531
# see also 5a19c08: security/cryptopp: Update to 8.7.0
.if ${ARCH} == i386 || ${ARCH} == amd64
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM
.endif

post-patch:
	${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" \
		${WRKSRC}/urbackupclient/backup_scripts/postgresqldump
	${FIND} ${WRKSRC} -type f \( -name '*.cpp' -o -name '*.h' \) \
		-exec ${REINPLACE_CMD} -e 's|auto_ptr|unique_ptr|g' {} +

post-stage:
	${INSTALL_DATA} ${WRKDIR}/urbackupclient.conf.sample-daemon \
		${STAGEDIR}${PREFIX}/etc/urbackup/urbackupclient.conf.sample

	${INSTALL_DATA} ${FILESDIR}/urbackupclient.conf-newsyslog \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/urbackupclient.conf

	${INSTALL_MAN} ${WRKSRC}/docs/urbackupclientbackend.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.for f in ${CONFFILES}
	${MV} ${STAGEDIR}${PREFIX}/etc/urbackup/${f} ${STAGEDIR}${PREFIX}/etc/urbackup/${f}.sample
.endfor

	${RM} ${STAGEDIR}/var/urbackup/version.txt
	${RM} ${STAGEDIR}${PREFIX}/share/urbackup/urbackup_ecdsa409k1.pub

.include <bsd.port.mk>
