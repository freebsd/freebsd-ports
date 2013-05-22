# New ports collection makefile for:	e93
# Date created:		21 June 1995
# Whom:			Satoshi Asami (asami)
#
# $FreeBSD$
#

PORTNAME=	e93
PORTVERSION=	1.4.2
CATEGORIES=	editors tcl
MASTER_SITES=	ftp://ftp.e93.org/pub/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}r${PORTVERSION:E}X
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A nifty editor based on Tcl

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11 xinerama
USE_TCL=	yes
USE_GMAKE=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" \
		TCL_INCLUDE="-I${TCL_INCLUDEDIR}" \
		TCL_LIB="-L${LOCALBASE}/lib" \
		TCL_VERSION="${TCL_VER:S/.//}" \
		X_INCLUDE="-I${LOCALBASE}/include" \
		X_LIB="-L${LOCALBASE}/lib" \
		EXTRALIBS="-lm" \
		CC="${CXX}" \
		OPTIONS="${CXXFLAGS}"

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++||g ; \
		 s|;make|;$$(MAKE)|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/<X11\/Intrinsic.h>/d ; \
		 /<X11\/Shell.h>/d' ${WRKSRC}/xgui/includes.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e93 ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/e93lib
.for ext in e93 regex syntaxmaps
	${INSTALL_DATA} ${WRKSRC}/README.${ext} ${PREFIX}/lib/e93lib
.endfor
	@(cd ${WRKSRC}/e93lib && ${COPYTREE_SHARE} . ${PREFIX}/lib/e93lib)

.include <bsd.port.mk>
