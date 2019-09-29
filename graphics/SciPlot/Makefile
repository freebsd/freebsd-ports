# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	SciPlot
PORTVERSION=	1.36
PORTREVISION=	5
CATEGORIES=	graphics math
MASTER_SITES=	XCONTRIB/widgets

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Full-featured Xt widget to display 2D data in a graph

LICENSE=	GPLv2

USES=		imake motif xorg
USE_XORG=	xt x11
MAKE_ENV=	EXTRA_DEFINES="-fPIC" LIBNAME=${LIBNAME}
USE_LDCONFIG=	yes

INCLUDES=	SciPlot.h SciPlotP.h SciPlotUtil.h
LIBNAME=	lib${PORTNAME:tl}	# Remove :tl for libSciPlot
PLIST_SUB=	LIBNAME=${LIBNAME}

PORTDOCS=	README SciPlot.html SciPlotDemo.html SciPlotProg.html
EXDATA=		data.txt
EXBINS=		realtime sciplot

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${INCLUDES:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${LIBNAME}.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/${LIBNAME}.so.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf ${LIBNAME}.so.0 ${STAGEDIR}${PREFIX}/lib/${LIBNAME}.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXDATA:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${EXBINS:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
