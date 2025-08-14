PORTNAME=	spirv-tools
PORTVERSION=	2024.4
DISTVERSIONSUFFIX=	-1.el9
PORTREVISION=	1
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tools for processing SPIR-V intermediate shader language modules (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/KhronosGroup/SPIRV-Tools

LICENSE=	APACHE20

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

BIN_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}
LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-libs-${DISTVERSIONFULL}

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
