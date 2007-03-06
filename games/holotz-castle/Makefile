# New ports collection makefile for: holotzcastle
# Date created:        4 January 2006
# Whom:                Pierre-Paul Lavoie <ppl@nbnet.nb.ca>
#
# $FreeBSD$
#

PORTNAME=	holotz-castle
PORTVERSION=	1.3.9
CATEGORIES=	games
MASTER_SITES=	http://www.mainreactor.net/holotzcastle/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ppl@nbnet.nb.ca
COMMENT=	A platform game with high doses of mystery

MAKE_ARGS=	HC_BASE=${PREFIX}/share/${PORTNAME}/ HC_BIN_DIR=${PREFIX}/bin/

USE_SDL=	image mixer sdl ttf
USE_X_PREFIX=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		doesn't work on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
