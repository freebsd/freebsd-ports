PORTNAME=	sdl_gfx
PORTVERSION=	2.0.27
DISTVERSIONSUFFIX=	-3.el9
CATEGORIES=	graphics linux
MASTER_SITES=	EPEL9
DISTNAME=	SDL_gfx-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	SDL graphics drawing primitives and other support functions (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.ferzkopp.net/Software/SDL_gfx-2.0/

LICENSE=	ZLIB

USES=		cpe linux:rl9
CPE_VENDOR=	libsdl
USE_LDCONFIG=	yes
USE_LINUX=	jpeg png sdl12 tiff
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL_gfx

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
