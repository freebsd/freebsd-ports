# Created by: Satoshi Asami (asami)
# $FreeBSD$

PORTNAME=	e93
PORTVERSION=	1.4.2
CATEGORIES=	editors tcl
MASTER_SITES=	ftp://ftp.e93.org/pub/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}r${PORTVERSION:E}X

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nifty editor based on Tcl

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
USES=		gmake tcl tar:tgz
USE_XORG=	x11 xinerama
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
	${INSTALL_PROGRAM} ${WRKSRC}/e93 ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/e93lib
	cd ${WRKSRC}/e93lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/e93lib
.for ext in e93 regex syntaxmaps
	${INSTALL_DATA} ${WRKSRC}/README.${ext} ${STAGEDIR}${PREFIX}/lib/e93lib
.endfor

.include <bsd.port.mk>
