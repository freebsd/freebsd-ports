PORTNAME=	lz4
PORTVERSION=	1.9.3
DISTVERSIONSUFFIX=	-5.el9
PORTREVISION=	1
CATEGORIES=	archivers linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	LZ4 compression library and utilities (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://lz4.github.io/lz4/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

CPE_VENDOR=	lz4_project

BIN_DISTNAMES=	${DISTNAME}
LIB_DISTNAMES=	lz4-libs-${PORTVERSION}${DISTVERSIONSUFFIX}

DESCR=		${PORTSDIR}/${PKGCATEGORY}/liblz4/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
