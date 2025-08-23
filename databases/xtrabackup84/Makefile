PORTNAME=	xtrabackup84
DISTVERSION=	8.4.0-4
CATEGORIES=	databases
MASTER_SITES=	https://downloads.percona.com/downloads/Percona-XtraBackup-8.4/Percona-XtraBackup-${DISTVERSION}/source/tarball/:percona
DISTFILES=	${PPORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:percona

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Open-source backup tool for InnoDB and XtraDB
WWW=		https://docs.percona.com/percona-xtrabackup/8.4/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

# MySQL8.2+ supports only 64-bit platforms
NOT_FOR_ARCHS= armv6 armv7 i386 powerpc

BUILD_DEPENDS=	protobuf>=3.0:devel/protobuf \
		rapidjson>=1.1.0:devel/rapidjson \
		libevent>=2.1:devel/libevent
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libev.so:devel/libev \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libicudata.so:devel/icu \
		libprotobuf-lite.so:devel/protobuf \
		libunwind.so:devel/libunwind \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	qpress:archivers/qpress

USES=		bison cmake compiler:c++14-lang cpe pkgconfig ssl
CPE_VENDOR=	percona
CMAKE_ARGS=	-DBUILD_CONFIG:STRING=xtrabackup_release \
		-DWITHOUT_COMPONENT_KEYRING_KMIP:STRING=yes \
		-DWITH_VERSION_CHECK=false

.for component in EDITLINE ICU LIBEVENT PROTOBUF RAPIDJSON ZSTD
CMAKE_ARGS+=	-DWITH_${component}:STRING=system
.endfor

CONFLICTS_INSTALL=	${PORTNAME:C/.$//}*

# Build fails without NDEBUG, so force it
CFLAGS+=	-DNDEBUG -fPIC
CXXFLAGS+=	-DNDEBUG -fPIC
CFLAGS_aarch64?=	-march=armv8-a+crc+crypto

PPORTNAME=	percona-xtrabackup
WRKSRC=		${WRKDIR}/${PPORTNAME}-${DISTVERSION}

.include <bsd.port.pre.mk>

KEEP_EXTRA=	lz4 zlib libbacktrace libcno boost unordered_dense

post-patch:
.for d in storage/innobase/xtrabackup/src sql/protobuf
	${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/${d}/CMakeLists.txt
.endfor

pre-configure:
.for dir in ${KEEP_EXTRA}
	@${MV} ${WRKSRC}/extra/${dir} ${WRKDIR}
.endfor
	@${RM} -r ${WRKSRC}/extra/*
.for dir in ${KEEP_EXTRA}
	@${MV} ${WRKDIR}/${dir} ${WRKSRC}/extra
.endfor

post-stage:
	@${RM} -r ${STAGEDIR}${PREFIX}/docs ${STAGEDIR}${PREFIX}/man
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/plugin/debug

.include <bsd.port.post.mk>
