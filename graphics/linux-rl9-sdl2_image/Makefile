PORTNAME=	sdl2_image
PORTVERSION=	2.8.2
DISTVERSIONSUFFIX=	-1.el9
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	EPEL9
DISTNAME=	SDL2_image-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Simple library to load images as SDL interfaces (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/libsdl-org/SDL_image/

LICENSE=	ZLIB

USES=		cpe linux:rl9
CPE_VENDOR=	libsdl
USE_LDCONFIG=	yes
USE_LINUX=	imageformats-libs sdl20
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL2_image

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
