# New ports collection makefile for:	graphviz
# Date created:		03 Feb 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	graphviz
PORTVERSION=	1.7.7
CATEGORIES=	graphics tk83
MASTER_SITES=	http://www.research.att.com/sw/tools/graphviz/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.8:${PORTSDIR}/print/freetype2 \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_XPM=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	--add-missing
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.3 -I${LOCALBASE}/include/tk8.3" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		TCLCONFIG=${LOCALBASE}/lib/tcl8.3/tclConfig.sh \
		TKCONFIG=${LOCALBASE}/lib/tk8.3/tkConfig.sh
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/lib/graphviz

MAN1=		acyclic.1 ccomps.1 colorize.1 dot.1 dotty.1 gc.1 gpr.1 \
		lefty.1 neato.1 nop.1 sccmap.1 tred.1 unflatten.1
MAN3=		agraph.3 cdt.3 expr.3 graph.3 pathplan.3
MANN=		gdtclft.n tcldgl.n tcldgr.n tcldot.n tkspline.n

PORTDOCS=	dotguide.pdf dottyguide.pdf gd.html leftyguide.pdf \
		neatoguide.pdf tcldot.html Dot.ref FAQ.html

post-extract:
	@${RM} ${WRKSRC}/cdt/ast_common.h

#post-patch:
#	@cd ${WRKSRC} && ${ACLOCAL} && ${AUTOHEADER} && libtoolize --force

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
