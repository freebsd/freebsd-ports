# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	sopwith
PORTVERSION=	1.8.4
CATEGORIES=	games
MASTER_SITES=	SF/sdl-${PORTNAME}/sdl_${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Classic WW1 biplane game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pkgconfig
USE_SDL=	sdl
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
