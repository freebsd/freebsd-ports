# New ports collection makefile for:	graphviz
# Date created:		03 Feb 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	graphviz
PORTVERSION=	1.7c
CATEGORIES=	graphics tk83
MASTER_SITES=	http://www.research.att.com/sw/tools/graphviz/dist/
DISTNAME=	gviz${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83

WRKSRC=		${WRKDIR}/gv${PORTVERSION}

USE_FREETYPE=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	--add-missing
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.3 -I${LOCALBASE}/include/tk8.3 -DHAVE_TERMIOS" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		TCLCONFIG=${LOCALBASE}/lib/tcl8.3/tclConfig.sh \
		TKCONFIG=${LOCALBASE}/lib/tk8.3/tkConfig.sh
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/lib/graphviz

MAN1=		dot.1 dotty.1 lefty.1 neato.1
MAN3=		agraph.3 cdt.3 graph.3 pathplan.3
MANN=		gdtclft.n tcldgl.n tcldgr.n tcldot.n tkspline.n

PORTDOCS=	dotguide.pdf dottyguide.pdf gd.html leftyguide.pdf \
		neatoguide.pdf tcldot.html Dot.ref

post-patch:
	@cd ${WRKSRC} && aclocal && autoheader && libtoolize --force

# the tarball contains object files!
post-configure:
	@cd ${WRKSRC} && ${GMAKE} clean

pre-build:
	@cd ${WRKSRC}/cdt && ./iffe - set cc ${CC} ${CFLAGS} : run \
		features/common > ast_common.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/graphviz
.for file in ${PORTDOCS} 
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/graphviz
.endfor
.endif

.include <bsd.port.mk>
