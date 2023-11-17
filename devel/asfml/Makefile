PORTNAME=	asfml
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.5
PORTREVISION=	1
CATEGORIES=	devel games graphics multimedia

MAINTAINER=	agh@riseup.net
COMMENT=	Ada bindings to the Simple and Fast Multimedia Library (SFML)
WWW=		https://mgrojo.github.io/ASFML/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	segfault: raised STORAGE_ERROR : s-intman.adb:136 explicit raise

BUILD_DEPENDS=	gprbuild>0:devel/gprbuild
LIB_DEPENDS=	libcsfml-system.so:devel/csfml

USES=		ada:12,run
USE_GCC=	yes:build
USE_GITHUB=	yes
GH_ACCOUNT=	mgrojo
GH_PROJECT=	${PORTNAME:tu}

EXTRACT_AFTER_ARGS=	--exclude include/generated

SUB_FILES=	${PORTNAME}.gpr

OPTIONS_DEFINE=	DEBUG DOCS EXAMPLES
OPTIONS_SUB=	yes

DOCS_DESC=	Install API reference documentation
EXAMPLES_DESC=	Build and install Ada SFML examples

EXAMPLES_RUN_DEPENDS+=	dejavu>0:x11-fonts/dejavu \
			webfonts>0:x11-fonts/webfonts

EXAMPLES_USES=	fonts:fc gl gmake
EXAMPLES_USE=	GL=glu,opengl

_GPR_ARGS=	-j${MAKE_JOBS_NUMBER} -p

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
_GPR_ARGS+=	-XASFML_BUILD_MODE=debug
WITH_DEBUG=	yes
.endif

post-extract:
	${MV} ${WRKSRC}/tests \
		${WRKSRC}/examples

post-patch:
	${REINPLACE_CMD} -e 's|%%DATA_AUDIO%%|${DATADIR}/audio/|' \
		-e 's|%%DATA_FONTS%%|${DATADIR}/fonts/|' \
		-e 's|%%DATA_GRAPHICS%%|${DATADIR}/graphics/|' \
		-e 's|%%PREFIX_FONTDIR%%|${FONTSDIR:C/${PORTNAME}//g}|' \
		${WRKSRC}/examples/example/main.adb \
		${WRKSRC}/examples/pong/pong.adb \
		${WRKSRC}/examples/renderwindow/main.adb \
		${WRKSRC}/examples/renderwindow/unicode.adb

do-build:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} gprbuild ${_GPR_ARGS} -P asfml)

do-build-EXAMPLES-on:
	(cd ${WRKSRC}/examples && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD})

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/gpr
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.gpr \
		${STAGEDIR}${PREFIX}/share/gpr/
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/*.ali \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/lib/*.a \
		${STAGEDIR}${PREFIX}/lib/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for DEMO in clock example graphics music opengl renderwindow thread window
	${INSTALL_DATA} ${WRKSRC}/examples/${DEMO}/main.adb \
		${STAGEDIR}${EXAMPLESDIR}/${DEMO}.adb
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${DEMO}/main \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-example-${DEMO}
.if ${DEMO} == renderwindow || ${DEMO} == window
	${INSTALL_DATA} ${WRKSRC}/examples/${DEMO}/unicode.adb \
		${STAGEDIR}${EXAMPLESDIR}/${DEMO}-unicode.adb
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${DEMO}/unicode \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-example-${DEMO}-unicode
.endif
.endfor
	${INSTALL_DATA} ${WRKSRC}/examples/pong/pong.adb \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/thread/thread_func.* \
		${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/examples/pong/pong \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-example-pong
	${MKDIR} ${STAGEDIR}${DATADIR}/audio
	${INSTALL_DATA} ${WRKSRC}/examples/pong/*.ogg \
		${STAGEDIR}${DATADIR}/audio
	${MKDIR} ${STAGEDIR}${DATADIR}/graphics
	${INSTALL_DATA} ${WRKSRC}/examples/renderwindow/*.png \
		${STAGEDIR}${DATADIR}/graphics
	${MKDIR} ${STAGEDIR}${DATADIR}/fonts
	${INSTALL_DATA} ${WRKSRC}/examples/renderwindow/aerial.ttf \
		${STAGEDIR}${DATADIR}/fonts

.include <bsd.port.mk>
