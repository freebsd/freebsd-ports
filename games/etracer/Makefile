# New ports collection makefile for:   extreme tux racer
# Date created:        22 February 2008
# Whom:                Peter Dunning
#
# $FreeBSD$
#

PORTNAME=		etracer
PORTVERSION=		0.4
PORTREVISION=		3
CATEGORIES=		games
MASTER_SITES=		SF/extremetuxracer/extreme-tuxracer/${PORTVERSION}
DISTNAME=		extremetuxracer-${PORTVERSION}

MAINTAINER=		peter_dunning@dsl.pipex.com
COMMENT=		The latest and greatest fork of the classic Tux Racer

LIB_DEPENDS=		png.5:${PORTSDIR}/graphics/png \
			freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=		mixer sdl
USE_GL=			gl glu glut
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

USE_TCL=		84+

.include <bsd.port.pre.mk>
CONFIGURE_ARGS=		--with-tcl="${TCL_LIBDIR}" \
			--with-tcl-inc="${TCL_INCLUDEDIR}" \
			--with-gl-libs="${LOCALBASE}/lib" \
			--with-gl-inc="${LOCALBASE}/include"

.include <bsd.port.post.mk>
