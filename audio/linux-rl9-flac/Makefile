PORTNAME=	flac
PORTVERSION=	1.3.3
DISTVERSIONSUFFIX=	-10.el9_2.1
PORTREVISION=	1
CATEGORIES=	audio linux
PKGNAMESUFFIX=	-libs

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Free lossless audio codec (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.xiph.org/flac/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libogg
USE_LINUX_RPM=	yes

CPE_VENDOR=	flac_project

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
