PORTNAME=	sdl_sound
PORTVERSION=	1.0.3
DISTVERSIONSUFFIX=	-37.el9
CATEGORIES=	audio linux
MASTER_SITES=	EPEL9
DISTNAME=	SDL_sound-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	SDL audio library and player for some popular sound file formats (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.icculus.org/SDL_sound/

LICENSE=	ZLIB

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	sdl20
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL_sound

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
