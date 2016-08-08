# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bloboats
PORTVERSION=	1.0.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://mirror.kapsi.fi/bloboats.dy.fi/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Boat racing game in the spirit of Elasto Mania or X-Moto

USES=		gmake
USE_SDL=	mixer image net sdl
USE_GL=		gl glu

MAKE_ENV+=	DATADIR="${DATADIR}" STAGEDIR=${STAGEDIR}

.include <bsd.port.mk>
