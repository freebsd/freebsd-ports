# New ports collection makefile for:	Open Scene Graph
# Date created:				26 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	osg
PORTVERSION=	0.8.45
CATEGORIES=	graphics
MASTER_SITES=	http://www.openscenegraph.org/download/snapshots/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2

DISTNAME=       OpenSceneGraph-${PORTVERSION}

USE_X_PREFIX=	yes
USE_MESA=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	OSGHOME=${WRKSRC}

# opt = optimized ($OPTF added); debug = debug ($DBGF added); opt is default
ALL_TARGET=	opt

post-install:
	  ${LN} -sf ${PREFIX}/share/osg/bin/sgv     ${PREFIX}/bin
	  ${LN} -sf ${PREFIX}/share/osg/bin/osgconv ${PREFIX}/bin
	  @${MKDIR} ${DOCSDIR}
	  ${CP} -r ${WRKSRC}/doc/ ${DOCSDIR}

.include <bsd.port.mk>
