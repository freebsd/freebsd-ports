# New ports collection makefile for:	graphviz
# Date created:		03 Feb 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	graphviz
PORTVERSION=	1.8.10
CATEGORIES=	graphics tk83
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/ARCHIVE/

MAINTAINER=	perky@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2 \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_XPM=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	--add-missing
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.3 -I${LOCALBASE}/include/tk8.3" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		TCLCONFIG=${LOCALBASE}/lib/tcl8.3/tclConfig.sh \
		TKCONFIG=${LOCALBASE}/lib/tk8.3/tkConfig.sh \
		AUTOHEADER=${LOCALBASE}/bin/autoheader213 \
		AUTOCONF=${LOCALBASE}/bin/autoconf213 \
		AUTOMAKE=${LOCALBASE}/bin/automake14 \
		ACLOCAL=${LOCALBASE}/bin/aclocal14
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/lib/graphviz
MAKE_ENV=	EXPR_COMPAT=yes

MAN1=		acyclic.1 ccomps.1 colorize.1 dot.1 dotty.1 gc.1 gpr.1 \
		lefty.1 neato.1 nop.1 prune.1 sccmap.1 tred.1 \
		twopi.1 unflatten.1
MAN3=		agraph.3 cdt.3 expr.3 graph.3 pack.3 pathplan.3
MANN=		gdtclft.n tcldgl.n tcldgr.n tcldot.n tkspline.n

PORTDOCS=	dotguide.pdf dottyguide.pdf gd.html leftyguide.pdf \
		neatoguide.pdf tcldot.html Dot.ref FAQ.html

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/iconv.h) || defined(WITH_ICONV)
LIB_DEPENDS+=   iconv.3:${PORTSDIR}/converters/libiconv
CONFIGURE_ARGS=	--with-iconvlibdir=${LOCALBASE}/lib
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
