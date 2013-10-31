# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	ayam
PORTVERSION=	1.20
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Ayam/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}.src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	3D modeling environment for the RenderMan interface

LICENSE=	BSD

LIB_DEPENDS=	libaqsis_util.so:${PORTSDIR}/graphics/aqsis \
		libtiff.so:${PORTSDIR}/graphics/tiff
BUILD_DEPENDS=	aqsl:${PORTSDIR}/graphics/aqsis

OPTIONS_DEFINE=	DOCS

USE_XORG=	xmu xext x11
USE_GL=		yes
USE_LDCONFIG=	${PREFIX}/lib/ayam
USES+=		tk:84
WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	Makefile.shared
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_JOBS_UNSAFE=	yes

AYAM_PLUGINS=	csphere mfio
PLUGINS_DIR=	${PREFIX}/lib/${PORTNAME}

.include <bsd.port.options.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not build on alpha
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/tcl/ayam.tcl
	@${REINPLACE_CMD} -e 's|^MF3DCFLAGS =|MF3DCFLAGS = -fPIC|g' \
		${WRKSRC}/MF3D/Makefile.mf3d
	@${REINPLACE_CMD} -e \
	   's|%%TCL_INCLUDEDIR%%|${TCL_INCLUDEDIR}|g; \
	    s|%%TCL_LIBDIR%%|${LOCALBASE}/lib|g; s|%%TCL_SHLIB_VER%%|${TCL_SHLIB_VER}|g; \
	    s|%%TK_INCLUDEDIR%%|${TK_INCLUDEDIR}|g; \
	    s|%%TK_LIBDIR%%|${LOCALBASE}/lib|g; s|%%TK_SHLIB_VER%%|${TK_SHLIB_VER}|g' \
	    ${WRKSRC}/Makefile.shared
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/../scn/shaders/Makefile

post-build:
	cd ${WRKSRC}/../scn/shaders && ${GMAKE} slx

do-install:
# binary and wrapper
	${INSTALL_PROGRAM} ${WRKSRC}/ayamsh ${STAGEDIR}${PREFIX}/bin
	@(${ECHO_CMD} "#!${SH}"; \
	  ${ECHO_CMD} "${PREFIX}/bin/ayamsh ${PLUGINS_DIR}/tcl/ayam.tcl \$$@" \
	) > ${STAGEDIR}${PREFIX}/bin/ayam
	@${CHMOD} ugo+x ${STAGEDIR}${PREFIX}/bin/ayam

# shaders
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ayam/shaders
	${INSTALL_DATA} ${WRKSRC}/../scn/shaders/*.slx ${STAGEDIR}${PREFIX}/lib/ayam/shaders

# plugins
	@${MKDIR} ${STAGEDIR}${PLUGINS_DIR}
.for i in ${AYAM_PLUGINS}
	${INSTALL_DATA} ${WRKSRC}/plugins/${i}.tcl ${STAGEDIR}${PLUGINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/${i}.so ${STAGEDIR}${PLUGINS_DIR}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/ayslx.so ${STAGEDIR}${PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/loadayslx.tcl ${STAGEDIR}${PLUGINS_DIR}

	${INSTALL_DATA} ${WRKSRC}/contrib/meta/*.tcl ${STAGEDIR}${PLUGINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/meta/metaobj.so ${STAGEDIR}${PLUGINS_DIR}

# tcl libs
	@${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/tcl
	${INSTALL_DATA} ${WRKSRC}/tcl/*.tcl ${STAGEDIR}${PLUGINS_DIR}/tcl
	@${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/tcl/BWidget-1.2.1
	${INSTALL_DATA} ${WRKSRC}/tcl/BWidget-1.2.1/*.tcl \
		${STAGEDIR}${PLUGINS_DIR}/tcl/BWidget-1.2.1
	@${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/tcl/BWidget-1.2.1/images
	${INSTALL_DATA} ${WRKSRC}/tcl/BWidget-1.2.1/images/* \
		${STAGEDIR}${PLUGINS_DIR}/tcl/BWidget-1.2.1/images
	@${MKDIR} ${STAGEDIR}${PLUGINS_DIR}/tcl/BWidget-1.2.1/lang
	${INSTALL_DATA} ${WRKSRC}/tcl/BWidget-1.2.1/lang/* \
		${STAGEDIR}${PLUGINS_DIR}/tcl/BWidget-1.2.1/lang

# data
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/lib/ayam-splash.gif ${STAGEDIR}${DATADIR}

# docs
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/Setup.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/ayam.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/refcard.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/refcard.tcl ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/html/*.html ${STAGEDIR}${DOCSDIR}/html
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html/pics
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/html/pics/* \
		${STAGEDIR}${DOCSDIR}/html/pics
.endif

.include <bsd.port.mk>
