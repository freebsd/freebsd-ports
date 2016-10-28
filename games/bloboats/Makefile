# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bloboats
PORTVERSION=	1.0.2
DISTVERSIONSUFFIX=	-source
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://bloboats.dy.fi/mirror/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Boat racing game in the spirit of Elasto Mania or X-Moto

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/copying.txt

USES=		gmake
USE_SDL=	mixer image net sdl
USE_GL=		gl glu

MAKE_ENV+=	DATADIR="${DATADIR}" STAGEDIR=${STAGEDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
