PORTNAME=	sdl2_ttf
PORTVERSION=	2.20.2
DISTVERSIONSUFFIX=	-1.el9
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	EPEL9
DISTNAME=	SDL2_ttf-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Simple library to load True Type Fonts as SDL interfaces (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://github.com/libsdl-org/SDL_ttf/

LICENSE=	ZLIB

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	imageformats-libs sdl20
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL2_ttf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
