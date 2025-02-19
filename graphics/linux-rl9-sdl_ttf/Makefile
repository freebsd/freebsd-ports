PORTNAME=	sdl_ttf
PORTVERSION=	2.0.11
DISTVERSIONSUFFIX=	-29.el9
CATEGORIES=	graphics linux
MASTER_SITES=	EPEL9
DISTNAME=	SDL_ttf-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Simple library to load True Type Fonts as SDL interfaces (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://github.com/libsdl-org/SDL_ttf/

LICENSE=	ZLIB

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	jpeg png sdl12 tiff
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL_image

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
