# Created by: Peter Dunning
# $FreeBSD$

PORTNAME=		etracer
PORTVERSION=		0.4
PORTREVISION=	10
CATEGORIES=		games
MASTER_SITES=		SF/extremetuxracer/extreme-tuxracer/${PORTVERSION}
DISTNAME=		extremetuxracer-${PORTVERSION}

MAINTAINER=		peter_dunning@dsl.pipex.com
COMMENT=		The latest and greatest fork of the classic Tux Racer

LIB_DEPENDS=		libpng15.so:${PORTSDIR}/graphics/png \
			libfreetype.so:${PORTSDIR}/print/freetype2

USE_SDL=		mixer sdl
USE_XORG=		x11 xi xext xmu xt
USE_GL=			gl glu glut
USES=			gmake pkgconfig tcl
GNU_CONFIGURE=		yes

CONFIGURE_ARGS=		--with-tcl="${TCL_LIBDIR}" \
			--with-tcl-inc="${TCL_INCLUDEDIR}" \
			--with-gl-libs="${LOCALBASE}/lib" \
			--with-gl-inc="${LOCALBASE}/include"

post-patch:
	${REINPLACE_CMD} -e 's|libpng12|libpng15|g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|int_p_NULL|NULL|g' \
		-e 's|png_infopp_NULL|NULL|g' \
		${WRKSRC}/src/ppgltk/images/png_reader.cpp

.include <bsd.port.mk>
