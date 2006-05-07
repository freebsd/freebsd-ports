# New ports collection makefile for:	moth
# Date created:				10 Sep 2005
# Whom:					Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	moth
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	http://moth.titanothere.com/moth/
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX} \
		lib${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	A simple to use 3D mesh editor

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

USE_GMAKE=	yes
USE_QT_VER=	3
USE_GL=		yes
USE_X_PREFIX=	yes
MAKE_ARGS=	CC="${CXX}" XLIBDIR="${X11BASE}/lib" MOC="${MOC}" \
		CFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS}" QTDIR="${X11BASE}" \
		GLINCLUDEDIR="${X11BASE}/include" \
		MOTH_INCLUDES="${WRKSRC_LIBMOTH}/include" \
		MOTH_LIBRARIES="${WRKSRC_LIBMOTH}/lib"
ALL_TARGET=	clean moth

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	manual.pdf

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
WRKSRC_LIBMOTH=	${WRKDIR}/lib${PORTNAME}_${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|^INCLUDES =|& ${QTCPPFLAGS} -I${LOCALBASE}/include|' \
		${WRKSRC_LIBMOTH}/Makefile ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|g++|${CXX}|; s|strip|# &|; \
		s|#\(-I$$(MOTH_INCLUDES)\)|\1|; \
		s|^LIBRARIES =|& -L${LOCALBASE}/lib|; \
		s|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/#include <GL\/glut\.h>/ d' \
		${WRKSRC_LIBMOTH}/src/MMaterial.cpp \
		${WRKSRC_LIBMOTH}/include/moth/MLightSource.h
	@${FIND} ${WRKSRC_LIBMOTH}/src ${WRKSRC}/src -name '*.cpp' -exec \
		${GREP} -lEe 'M_PI|exp\(|sqrt\(|fabs\(' "{}" \; | ${XARGS} -L 1 \
		${REINPLACE_CMD} -Ee '1s|^|#include <math.h>|; 1G'

# build libmoth first
pre-build:
	@(cd ${WRKSRC_LIBMOTH} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
