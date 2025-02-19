PORTNAME=	sdl2_mixer
PORTVERSION=	2.6.3
DISTVERSIONSUFFIX=	-1.el9
CATEGORIES=	audio linux
MASTER_SITES=	EPEL9
DISTNAME=	SDL2_mixer-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Sample multi-channel audio mixer library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/libsdl-org/SDL_mixer/

LICENSE=	ZLIB

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	sdl20
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL2_mixer

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
