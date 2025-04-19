PORTNAME=	sdl2_gfx
PORTVERSION=	1.0.4
DISTVERSIONSUFFIX=	-10.el9
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	EPEL9
DISTNAME=	SDL2_gfx-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	SDL graphics drawing primitives and other support functions (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.ferzkopp.net/Software/SDL_gfx-2.0/

LICENSE=	ZLIB

USES=		cpe linux:rl9
CPE_VENDOR=	libsdl
USE_LDCONFIG=	yes
USE_LINUX=	imageformats-libs sdl20
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL2_gfx

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
