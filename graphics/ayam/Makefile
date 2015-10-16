# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	ayam
PORTVERSION=	1.22
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Ayam/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D modeling environment for the RenderMan interface

LICENSE=	Ayam # similar to tcl/tk license
LICENSE_NAME=	Ayam License
LICENSE_FILE=	${WRKSRC}/../License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libaqsis_util.so:${PORTSDIR}/graphics/aqsis \
		libtiff.so:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USES=		gmake tk
USE_XORG=	x11 xext xmu
USE_GL=		glu
MAKE_ENV=	TCL_INCLUDEDIR="${TCL_INCLUDEDIR}" \
		TCL_SHLIB_VER="${TCL_SHLIB_VER}" \
		TK_INCLUDEDIR="${TK_INCLUDEDIR}" \
		TK_SHLIB_VER="${TK_SHLIB_VER}"
MAKEFILE=	Makefile.shared
USE_LDCONFIG=	${PREFIX}/lib/ayam
MAKE_JOBS_UNSAFE=	yes

DESKTOP_ENTRIES="Ayam" "" "" "ayam" "" ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/^MF3DCFLAGS/s|=.*|= -fPIC|' \
		${WRKSRC}/MF3D/Makefile.mf3d
	@${REINPLACE_CMD} -e \
		's|interp->errorLine;|Tcl_GetErrorLine(interp);|' \
		${WRKSRC}/objects/script.c
	@${REINPLACE_CMD} -e \
		's|".*\(ayam-splash.gif\)"|"${DATADIR}/\1"|' \
		${WRKSRC}/tcl/ayam.tcl
	@${REINPLACE_CMD} -e \
		's| firefox | xdg-open |' \
		${WRKSRC}/tcl/browser.tcl
	@${REINPLACE_CMD} -e \
		'/^AQSL/s|=.*|= ${LOCALBASE}/bin/aqsl|' \
		${WRKSRC}/../scn/shaders/Makefile

post-build:
	cd ${WRKSRC}/../scn/shaders && ${MAKE_CMD} slx
	@${ECHO_CMD} -n > ${WRKSRC}/../bin/ayam
	@${ECHO_CMD} "#!${SH}" >> ${WRKSRC}/../bin/ayam
	@${ECHO_CMD} "${PREFIX}/bin/ayamsh ${PREFIX}/lib/ayam/tcl/ayam.tcl \$$@" \
		>> ${WRKSRC}/../bin/ayam

do-install:
# binary and wrapper
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ayamsh ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/../bin && ${INSTALL_SCRIPT} ayam ${STAGEDIR}${PREFIX}/bin)
# shaders
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ayam/shaders
	(cd ${WRKSRC}/../scn/shaders && ${INSTALL_DATA} *.slx \
		${STAGEDIR}${PREFIX}/lib/ayam/shaders)
# plugins
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ayam
	(cd ${WRKSRC}/plugins && ${INSTALL_LIB}  \
		ayslx.so csphere.so mfio.so \
		${STAGEDIR}${PREFIX}/lib/ayam)
	(cd ${WRKSRC}/plugins && ${INSTALL_DATA} \
		csphere.tcl loadayslx.tcl mfio.tcl \
		${STAGEDIR}${PREFIX}/lib/ayam)
	(cd ${WRKSRC}/contrib/meta && ${INSTALL_LIB} *.so \
		${STAGEDIR}${PREFIX}/lib/ayam)
	(cd ${WRKSRC}/contrib/meta && ${INSTALL_DATA} *.tcl \
		${STAGEDIR}${PREFIX}/lib/ayam)
# tcl libs
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ayam/tcl \
		${STAGEDIR}${PREFIX}/lib/ayam/tcl/BWidget-1.2.1 \
		${STAGEDIR}${PREFIX}/lib/ayam/tcl/BWidget-1.2.1/images \
		${STAGEDIR}${PREFIX}/lib/ayam/tcl/BWidget-1.2.1/lang
	${INSTALL_DATA} ${WRKSRC}/tcl/*.tcl \
		${STAGEDIR}${PREFIX}/lib/ayam/tcl
	${INSTALL_DATA} ${WRKSRC}/tcl/BWidget-1.2.1/*.tcl \
		${STAGEDIR}${PREFIX}/lib/ayam/tcl/BWidget-1.2.1
	${INSTALL_DATA} ${WRKSRC}/tcl/BWidget-1.2.1/images/* \
		${STAGEDIR}${PREFIX}/lib/ayam/tcl/BWidget-1.2.1/images
	${INSTALL_DATA} ${WRKSRC}/tcl/BWidget-1.2.1/lang/* \
		${STAGEDIR}${PREFIX}/lib/ayam/tcl/BWidget-1.2.1/lang
# data
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/lib/ayam-splash.gif \
		${STAGEDIR}${DATADIR}
# docs
	@${MKDIR} ${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${DOCSDIR}/html \
		${STAGEDIR}${DOCSDIR}/html/pics
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/Setup.txt ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/${PORTNAME}/doc && ${INSTALL_DATA} \
		ayam.pdf refcard.pdf refcard.tcl ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/html/*.html \
		${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/html/pics/* \
		${STAGEDIR}${DOCSDIR}/html/pics

.include <bsd.port.mk>
