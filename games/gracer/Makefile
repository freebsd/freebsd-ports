# New ports collection makefile for:   gracer
# Version required:    0.1.4
# Date created:        Fri Jul 30 20:50:16 MET DST 1999
# Whom:                nox@jelal.kn-bremen.de
#
# $FreeBSD$
#

DISTNAME= 	gracer-0.1.4
CATEGORIES=	games
MASTER_SITES=	http://arch.comp.kyutech.ac.jp/~matsu/my_products/gtk/race/

MAINTAINER=	nox@jelal.kn-bremen.de

BUILD_DEPENDS=	${X11BASE}/lib/libsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3 \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.3:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tcl82.1:${PORTSDIR}/lang/tcl82

USE_AUTOCONF=	YES
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
			  -I${LOCALBASE}/include/tcl8.2 \
			  -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
USE_GMAKE=	yes
# for plib (sound):
USE_NEWGCC=	yes
CONFIGURE_ARGS+= --with-plib=${X11BASE}

.include <bsd.port.mk>
