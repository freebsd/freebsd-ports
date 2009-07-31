# New ports collection makefile for:	evas
# Date created:		24 Oct 2000
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	evas
PORTVERSION=	0.9.9.042
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A hardware accelerated canvas API (meta-port)

NO_BUILD=	yes
USE_EFL=	evas

EVAS_ENGINES=	buffer opengl sdl x11 xrender
EVAS_LOADERS=	edb eet gif jpeg png svg tiff xpm

.for NODE in ${EVAS_ENGINES}
OPTIONS+=	${NODE:U} "Install ${NODE} evas engine" on
.endfor

.for NODE in ${EVAS_LOADERS}
OPTIONS+=	${NODE:U} "Install ${NODE} evas loader" on
.endfor

.include <bsd.port.pre.mk>

.for NODE in ${EVAS_ENGINES}
. if !defined(WITHOUT_${NODE:U})
USE_EFL_EVAS_ENGINES+=	${NODE}
. endif
.endfor

.for NODE in ${EVAS_LOADERS}
. if !defined(WITHOUT_${NODE:U})
USE_EFL_EVAS_LOADERS+=	${NODE}
. endif
.endfor

do-install:
	${DO_NADA}

.include <bsd.port.post.mk>
