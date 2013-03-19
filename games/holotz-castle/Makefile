# Created by: Pierre-Paul Lavoie <ppl@nbnet.nb.ca>
# $FreeBSD$

PORTNAME=	holotz-castle
PORTVERSION=	1.3.13
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.mainreactor.net/holotzcastle/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A platform game with high doses of mystery

MAKE_ARGS=	HC_BASE=${PREFIX}/share/${PORTNAME}/ HC_BIN_DIR=${PREFIX}/bin/
MAKE_JOBS_UNSAFE=	yes

USE_GL=		gl
USE_SDL=	image mixer sdl ttf
USE_GMAKE=	yes

.include <bsd.port.mk>
