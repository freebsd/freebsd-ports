# New ports collection makefile for:	graphviz
# Date created:		03 Feb 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	graphviz
PORTVERSION=	1.6
CATEGORIES=	graphics tk83
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83 \
		ttf.4:${PORTSDIR}/print/freetype \
		Xpm.4:${PORTSDIR}/graphics/xpm

USE_AUTOCONF=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.3 -I${LOCALBASE}/include/tk8.3 -DHAVE_TERMIOS" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		TCLCONFIG=${LOCALBASE}/lib/tcl8.3/tclConfig.sh \
		TKCONFIG=${LOCALBASE}/lib/tk8.3/tkConfig.sh
USE_GMAKE=	yes

MAN1=	dot.1 dotty.1 lefty.1 neato.1
MAN3=	agraph.3 cdt.3 graph.3 pathplan.3
MANN=	gdtclft.n tcldgl.n tcldgr.n tcldot.n tkspline.n

.include <bsd.port.mk>
