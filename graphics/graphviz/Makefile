# New ports collection makefile for:	graphviz
# Date created:		03 Feb 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	graphviz
PORTVERSION=	2.2
CATEGORIES=	graphics tk84
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/ARCHIVE/

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Graph Visualization Software from AT&T and Bell Labs

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2 \
		tk84.1:${PORTSDIR}/x11-toolkits/tk84 \
		expat.5:${PORTSDIR}/textproc/expat2

USE_BISON=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.4 -I${LOCALBASE}/include/tk8.4" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		TCLCONFIG=${LOCALBASE}/lib/tcl8.4/tclConfig.sh \
		TKCONFIG=${LOCALBASE}/lib/tk8.4/tkConfig.sh \
		MISSING=${TRUE}
CONFIGURE_ARGS=	--program-transform-name="s/x/x/" \
		--with-iconvlibdir=${LOCALBASE}/lib \
		--with-tclsh=${LOCALBASE}/tcl8.4 \
		--with-wish=${LOCALBASE}/wish8.4
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/lib/graphviz
MAKE_ENV=	EXPR_COMPAT=yes MISSING=${TRUE}

MAN1=		acyclic.1 bcomps.1 ccomps.1 dijkstra.1 dot.1 dotneato-config.1 \
		dotty.1 gc.1 gvcolor.1 gvpack.1 gvpr.1 gxl2dot.1 lefty.1 \
		lneato.1 nop.1 prune.1 sccmap.1 tred.1 unflatten.1
MAN3=		agraph.3 cdt.3 expr.3 graph.3 pack.3 pathplan.3
MANN=		gdtclft.n tcldot.n tkspline.n
MLINKS=		dot.1 circo.1 \
		gxl2dot.1 dot2gxl.1 \
		dot.1 fdp.1 \
		dot.1 neato.1 \
		dot.1 twopi.1

MYPORTDOCS=	dotguide.pdf dottyguide.pdf leftyguide.pdf \
		neatoguide.pdf Dot.ref FAQ.html

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
