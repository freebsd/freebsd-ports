PORTNAME=	asfml
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	devel games graphics multimedia

MAINTAINER=	ada@FreeBSD.org
COMMENT=	Ada bindings to the Simple and Fast Multimedia Library (SFML)
WWW=		https://mgrojo.github.io/ASFML/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	gprbuild>0:devel/gprbuild
LIB_DEPENDS=	libcsfml-audio.so:devel/csfml \
		libcsfml-graphics.so:devel/csfml \
		libcsfml-network.so:devel/csfml \
		libcsfml-system.so:devel/csfml \
		libcsfml-window.so:devel/csfml

USES=		ada:run
USE_GITHUB=	yes
GH_ACCOUNT=	mgrojo
GH_PROJECT=	${PORTNAME:tu}

MAKE_CMD=	gprbuild

EXTRACT_AFTER_ARGS=	${_DIST_EXCLUDES:S,^,--exclude ,}

PORTEXAMPLES=	*

OPTIONS_DEFINE=			DOCS EXAMPLES
OPTIONS_DEFAULT=		CONTRACTS OPTIMIZE RUNTIME STATIC STYLE
OPTIONS_GROUP=			TOOLCHAINCONFIG
OPTIONS_GROUP_TOOLCHAINCONFIG=	CONTRACTS RUNTIME STATIC STYLE
OPTIONS_SUB=			yes

CONTRACTS_DESC=		Disable/Enable Pragma asserations and Contracts
EXAMPLES_DESC=		Build and install Ada SFML examples
RUNTIME_DESC=		Disable/Enable runtime checks
STATIC_DESC=		Warn on compile time assertations failing
STYLE_DESC=		Check for style violations during compilation
TOOLCHAINCONFIG_DESC=	Enable/Disable tool-chain static/runtime checking

CONTRACTS_VARS_OFF=	_GPR_PROJECT_ARGS+=-XASFML_CONTRACTS=disabled
EXAMPLES_USES=		fonts:fc gl
EXAMPLES_USE=		GL=glu,opengl
RUNTIME_VARS_OFF=	_GPR_PROJECT_ARGS+=-XASFML_RUNTIME_CHECKS=disabled
STATIC_VARS_OFF=	_GPR_PROJECT_ARGS+=-XASFML_COMPILE_CHECKS=disabled
STYLE_VARS_OFF=		_GPR_PROJECT_ARGS+=-XASFML_STYLE_CHECKS=disabled

_ASFML_EXAMPLES=	clock example ftp graphics music opengl pong \
			renderwindow sound sound_spatial soundstream \
			vertexbuffer vulkan window
_DATADIR_AUDIO=		${DATADIR}/audio
_DATADIR_IMAGES=	${DATADIR}/images
_DIST_EXCLUDES=		include/generated tests/thread
_GPRBUILD_ARGS=		${_GPR_PROJECT_ARGS} -j${MAKE_JOBS_NUMBER} -p -vh -vP2
_GPRINSTALL_ARGS=	${_GPR_PROJECT_ARGS} --no-manifest \
			--prefix='${STAGEDIR}${PREFIX}' -p -v
_GPR_PROJECT_ARGS=	-XASFML_BUILD_MODE+=${WITH_DEBUG:Uoptimize:Ddebug}

post-extract:
	${MV} ${WRKSRC}/tests \
		${WRKSRC}/examples

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR_AUDIO%%|${_DATADIR_AUDIO}|' \
		-e 's|%%DATADIR_IMAGES%%|${_DATADIR_IMAGES}|' \
		-e 's|%%FONTSDIR%%|${FONTSDIR}|' \
		${WRKSRC}/examples/example/main.adb \
		${WRKSRC}/examples/pong/pong.adb \
		${WRKSRC}/examples/renderwindow/main.adb \
		${WRKSRC}/examples/renderwindow/unicode.adb \
		${WRKSRC}/examples/sound_spatial/main.adb

do-build:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_GPRBUILD_ARGS} -P \
		${PORTNAME})

do-build-EXAMPLES-on:
. for _example in ${_ASFML_EXAMPLES}
.  if ${_example} == pong
	(cd ${WRKSRC}/examples && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_GPRBUILD_ARGS} -P \
		${_example}/pong)
.  else
	(cd ${WRKSRC}/examples && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_GPRBUILD_ARGS} -P \
		${_example}/main)
.  endif
. endfor

do-install:
	(cd ${WRKSRC}/ && \
		${SETENV} ${MAKE_ENV} gprinstall ${_GPRINSTALL_ARGS} --ali-subdir=libdata/${PORTNAME} \
		--lib-subdir=lib/${PORTNAME} --sources-subdir=include/${PORTNAME} \
		-P ${PORTNAME})

do-install-DOCS-on:
	(cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
. for _example in ${_ASFML_EXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${_example}
	${INSTALL_DATA} ${WRKSRC}/examples/${_example}/*.ad[bs] \
		${STAGEDIR}${EXAMPLESDIR}/${_example}
.  if ${_example} == pong
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${_example}/pong \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-example-${_example}
.  elif ${_example} == renderwindow
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${_example}/main \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-example-${_example}
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${_example}/unicode \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-example-${_example}-unicode
.  elif ${_example} == window
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${_example}/main \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-example-${_example}
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${_example}/unicode \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-example-${_example}-unicode
.  else
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${_example}/main \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-example-${_example}
.  endif
. endfor
	${MKDIR} ${STAGEDIR}${_DATADIR_AUDIO}
	${FIND} ${WRKSRC}/examples/ -type f -name *.ogg -exec ${INSTALL_DATA} \
		{} ${STAGEDIR}${_DATADIR_AUDIO} \;
	${MKDIR} ${STAGEDIR}${_DATADIR_IMAGES}
	${FIND} ${WRKSRC}/ -type f -name *.png -exec ${INSTALL_DATA} {} ${STAGEDIR}${_DATADIR_IMAGES} \
		\;
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${FIND} ${WRKSRC}/examples/ -type f -name *.ttf -exec ${INSTALL_DATA} \
		{} ${STAGEDIR}${FONTSDIR} \;

.include <bsd.port.mk>
