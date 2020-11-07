# Created by: Alex Samorukov <samm@freebsd.org>
# $FreeBSD$

PORTNAME=	xtrabackup
PORTVERSION=	8.0.14
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	https://www.percona.com/downloads/Percona-XtraBackup-${PORTVERSION:R}/Percona-XtraBackup-${PORTVERSION}/source/tarball/ \
		https://github.com/percona/percona-xtrabackup/archive/
PKGNAMESUFFIX=	8
DISTNAME=	percona-${PORTNAME}-${PORTVERSION}

MAINTAINER=	eugene@zhegan.in
COMMENT=	Open-source backup tool for InnoDB and XtraDB

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xxd:editors/vim-console \
		boost-libs>=1.72.0:devel/boost-libs \
		protobuf>=3.0:devel/protobuf \
		rapidjson>=1.1.0:devel/rapidjson \
		libevent>=2.1:devel/libevent
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libev.so:devel/libev \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libicudata.so:devel/icu \
		libunwind.so:devel/libunwind \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	qpress:archivers/qpress

CONFLICTS_INSTALL=	${PORTNAME}

USES=		bison cmake compiler:c++14-lang cpe pkgconfig ssl
CPE_VENDOR=	percona
CMAKE_ARGS=	-DBUILD_CONFIG:STRING=xtrabackup_release
.for component in EDITLINE ICU LIBEVENT PROTOBUF RAPIDJSON ZSTD
CMAKE_ARGS+=	-DWITH_${component}:STRING=system
.endfor

post-patch:
# Delete bundled components so we won't accidentally use them, except LZ4
# which cannot be removed just yet
	@${MV} ${WRKSRC}/extra/lz4 ${WRKSRC}
	@${RM} -r ${WRKSRC}/extra/*
	@${MV} ${WRKSRC}/lz4 ${WRKSRC}/extra

post-stage:
	@${RM} -r ${STAGEDIR}${PREFIX}/docs
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/plugin/debug

.include <bsd.port.mk>
