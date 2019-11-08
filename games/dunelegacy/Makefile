# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dunelegacy
PORTVERSION=	0.96.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Open source clone of Dune II

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lib pkgconfig sdl tar:bzip2
GNU_CONFIGURE=	yes
USE_SDL=	sdl2 mixer2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|MIX_INIT_FLUIDSYNTH|MIX_INIT_MID|g' \
		${WRKSRC}/src/FileClasses/music/*.cpp

.include <bsd.port.mk>
