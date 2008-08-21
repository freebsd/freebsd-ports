# New ports collection makefile for:   extreme tux racer
# Date created:        22 February 2008
# Whom:                Peter Dunning
#
# $FreeBSD$
#

PORTNAME=		etracer
PORTVERSION=		0.4
CATEGORIES=		games
MASTER_SITES=		SF/extremetuxracer
DISTNAME=		extremetuxracer-${PORTVERSION}

MAINTAINER=		peter_dunning@dsl.pipex.com
COMMENT=		The latest and greatest fork of the classic Tux Racer

LIB_DEPENDS=		tcl85:${PORTSDIR}/lang/tcl85 \
			png.5:${PORTSDIR}/graphics/png \
			freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=		mixer sdl
USE_GL=			gl glu glut
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-tcl=${PREFIX}/lib/tcl8.5 \
			--with-tcl-inc=${PREFIX}/include/tcl8.5 \
			--with-gl-libs="${LOCALBASE}/lib" \
			--with-gl-inc="${LOCALBASE}/include"

.include <bsd.port.mk>
