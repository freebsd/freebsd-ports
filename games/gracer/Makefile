# New ports collection makefile for:   gracer
# Version required:    0.1.0
# Date created:        Fri Jul 30 20:50:16 MET DST 1999
# Whom:                nox@jelal.kn-bremen.de
#
# $FreeBSD$
#

DISTNAME= 	gracer-0.1.0
CATEGORIES=	games
MASTER_SITES=	http://arch.comp.kyutech.ac.jp/~matsu/my_products/gtk/race/

MAINTAINER=	nox@jelal.kn-bremen.de

LIB_DEPENDS=	MesaGL.14:${PORTSDIR}/graphics/Mesa3 \
		gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tcl80.1:${PORTSDIR}/lang/tcl80

# doesn't work, program still looks for its files in /usr/local
#USE_X_PREFIX=	yes
USE_AUTOCONF=	yes
CFLAGS+=	-I${X11BASE}/include -I${LOCALBASE}/include -L${LOCALBASE}/lib
CONFIGURE_ENV+=	"CPP=cc -E -I${LOCALBASE}/include"
USE_GMAKE=	yes

.include <bsd.port.mk>
