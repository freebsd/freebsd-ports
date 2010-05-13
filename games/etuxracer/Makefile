# New ports collection makefile for:	games/etuxracer
# Date created:				4 April 2010
# Whom:					Chris Petrik <chris@officialunix.com>
# based on:				games/tuxracer by Eric Anholt
#
# $FreeBSD$
#

PORTNAME=	etuxracer
PORTVERSION=	0.4
CATEGORIES=	games
MASTER_SITES=	SF/extremetuxracer/extreme-tuxracer/${PORTVERSION}/
DISTNAME=	extremetuxracer-${PORTVERSION}

MAINTAINER=	chris@officialunix.com
COMMENT=	A 3d penguin racing game using OpenGL

LIB_DEPENDS=	tcl85:${PORTSDIR}/lang/tcl85 \
		png.6:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2

USE_SDL=	mixer sdl
USE_GL=		gl
USE_XORG=	x11 xt xmu xi
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	THREAD_LIB="${PTHREAD_LIBS}"
MAKE_ENV=	${CONFIGURE_ENV}
CONFIGURE_ARGS=	--with-tcl="${LOCALBASE}/lib/tcl8.5"\
		--with-tcl-inc="${LOCALBASE}/include/tcl8.5" \
		--with-tcl-lib-name="tcl85" \
		--with-gl-libs="${LOCALBASE}/lib" \
		--with-gl-inc="${LOCALBASE}/include" \
		--with-data-dir=${PREFIX}/share/extremetuxracer
WRKSRC=	${WRKDIR}/extremetuxracer-${PORTVERSION}
.include <bsd.port.mk>
