PORTNAME=	gprbuild
DISTVERSIONPREFIX=	v
DISTVERSION=	26.0.0 # Sync updating with textproc/xmlada.
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	ada@FreeBSD.org
COMMENT=	Advanced multi-language build system
WWW=		https://docs.adacore.com/gprbuild-docs/html/gprbuild_ug.html

LICENSE=	GPLv3+ GPLv3RLE+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING3
LICENSE_FILE_GPLv3RLE+ =	${WRKSRC}/COPYING.RUNTIME

# See PR 296655
IGNORE_i386=	It builds, but cannot be used to build other ports

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx@${PY_FLAVOR}

USES=		ada:run python:build
USE_BINUTILS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_PROJECT=	gprconfig_kb:kb xmlada:xa

CONFIGURE_TARGET=	${_CONFIGURE_ARCH}-portbld-${_CONFIGURE_PLATFORM}

MAKE_CMD=	gprbuild

NO_SHLIB_REQUIRES_GLOB=	libgnarl-${_ada_version}.so libgnat-${_ada_version}.so

PLIST_SUB=	SO_VERSION=${DISTVERSION}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=			DOCS EXAMPLES
OPTIONS_DEFAULT=		PRODUCTION
OPTIONS_RADIO=			BUILDTYPE
OPTIONS_RADIO_BUILDTYPE=	COVERAGE DEBUG PRODUCTION PROFILE

BUILDTYPE_DESC=		Application production type
COVERAGE_DESC=		Produce instrumentation data for analysis
DEBUG_DESC=		Produce symbols for debugging
DOCS_DESC=		Install extensive online HTML documentation
PRODUCTION_DESC=	Produce for release/production
PROFILE_DESC=		Produce instrumentation data for profiling

COVERAGE_VARS=		_GPRBUILD_GPR_PROJECT_ARGS=-XGPRBUILD_BUILD=coverage \
			_LIBGPR_GPR_PROJECT_ARGS=-XGPR_BUILD=coverage \
			_XMLADA_GPR_PROJECT_ARGS=-XXMLADA_BUILD_MODE=coverage
DEBUG_VARS=		_GPRBUILD_GPR_PROJECT_ARGS=-XGPRBUILD_BUILD=debug \
			_LIBGPR_GPR_PROJECT_ARGS=-XGPR_BUILD=debug \
			_XMLADA_GPR_PROJECT_ARGS=-XXMLADA_BUILD_MODE=Debug
PRODUCTION_VARS=	_GPRBUILD_GPR_PROJECT_ARGS=-XGPRBUILD_BUILD=production \
			_LIBGPR_GPR_PROJECT_ARGS=-XGPR_BUILD=production \
			_XMLADA_GPR_PROJECT_ARGS=-XXMLADA_BUILD_MODE=Production
PROFILE_VARS=		_GPRBUILD_GPR_PROJECT_ARGS=-XGPRBUILD_BUILD=profiling \
			_LIBGPR_GPR_PROJECT_ARGS=-XGPR_BUILD=profiling \
			_XMLADA_GPR_PROJECT_ARGS=-XXMLADA_BUILD_MODE=profile

_BOOTSTRAP_GNATMAKE_FLAGS=		GNATMAKEFLAGS="-D ${_BOOTSTRAP_WRKDIR} -j${MAKE_JOBS_NUMBER} -vh"
_BOOTSTRAP_GPR_PREFIX=			${_BOOTSTRAP_PREFIX}/share/gpr
_BOOTSTRAP_PATH=			${_BOOTSTRAP_PREFIX}/bin
_BOOTSTRAP_PREFIX=			${WRKDIR}/bootstrap
_BOOTSTRAP_WRKDIR=			${_BOOTSTRAP_PREFIX}/build
_BOOTSTRAP_XMLADA_GPRBUILD_ARGS=	${_GPRBUILD_ARGS} \
					${_XMLADA_GPR_PROJECT_ARGS}
_BOOTSTRAP_XMLADA_GPRINSTALL_ARGS=	${_XMLADA_GPR_PROJECT_ARGS} \
					--no-manifest \
					--prefix='${_BOOTSTRAP_PREFIX}' -p -v
_BOOTSTRAP_XMLADA_LIBRARY_TYPES=	static-pic
_BOOTSTRAP_XMLADA_WRKSRC=		${WRKDIR}/xmlada-${DISTVERSION}
_CONFIGURE_ARCH=			${ARCH:S/amd64/x86_64/}
_CONFIGURE_PLATFORM=			${OPSYS:tl}${OSREL}
_DIST_BUILD_DATE=			20251007
_DIST_BUILD_TYPE=			FSF
_DOCS_INSTALL_EXCLUDES=			"-not -name .buildinfo -not -regex ^./_sources.*"
_FINAL_STAGE_GPRBUILD_ARGS=		${_FINAL_STAGE_GPR_ARGS} \
					${_GPRBUILD_ARGS}
_FINAL_STAGE_GPRINSTALL_ARGS=		${_FINAL_STAGE_GPR_ARGS} \
					${_GPRINSTALL_ARGS}
_FINAL_STAGE_GPR_ARGS=			${_GPRBUILD_GPR_PROJECT_ARGS} \
					-aP${_BOOTSTRAP_GPR_PREFIX}
_FINAL_STAGE_LIBGPR_BUILD_ARGS=		${_GPRBUILD_ARGS} \
					${_LIBGPR_GPR_PROJECT_ARGS} \
					-aP${_BOOTSTRAP_GPR_PREFIX}
_FINAL_STAGE_LIBGPR_INSTALL_ARGS=	${_GPRINSTALL_ARGS} \
					${_LIBGPR_GPR_PROJECT_ARGS} \
					-aP${_BOOTSTRAP_GPR_PREFIX}
_GPRBUILD_ARGS=				-j${MAKE_JOBS_NUMBER} -p -vh -vP2
_GPRBUILD_GPR_PROJECT_ARGS=		-XGPRBUILD_BUILD=${WITH_DEBUG:Uproduction:Ddebug}
_GPRBUILD_LIBRARY_TYPES=		static-pic
_GPRINSTALL_ARGS=			--no-manifest \
					--prefix='${STAGEDIR}${PREFIX}' -p -v
_LIBGPR_LIBRARY_TYPES=			relocatable static-pic
_LIBGPR_GPR_PROJECT_ARGS=		-XGPR_BUILD=${WITH_DEBUG:Uproduction:Ddebug}
_XMLADA_GPR_PROJECT_ARGS=		-XXMLADA_BUILD_MODE=${WITH_DEBUG:UProduction:DDebug}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
# Attenuate compiler warnings generated from conflicting styles between libgpr
# and the compiler, and conflicting type sizes in an Unchecked_Conversion in
# the compiler
_LIBGPR_GPRBUILD_CARGS=	-cargs:Ada -gnatwZ -gnaty-g
.else
_LIBGPR_GPRBUILD_CARGS=
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|"${PREFIX}"|' \
		${WRKSRC}/gpr/src/gpr-env.adb \
		${WRKSRC}/gpr/src/gpr-conf.adb \
		${WRKSRC}/doc/gprbuild_ug/gnat_project_manager.rst
	${REINPLACE_CMD} -e 's|%%SO_VERSION%%|${DISTVERSION}|' \
		${WRKSRC}/gpr/gpr.gpr
	${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|' \
		-e 's|%%DIST_BUILD_DATE%%|${_DIST_BUILD_DATE}|' \
		-e 's|%%DIST_BUILD_TYPE%%|${_DIST_BUILD_TYPE}|' \
		${WRKSRC}/gpr/src/gpr-version.ads
	${REINPLACE_CMD} -e 's|@PACKAGE_VERSION@|${DISTVERSION}|' \
		-e 's|@SO_EXT@|.so|' \
		${_BOOTSTRAP_XMLADA_WRKSRC}/xmlada_shared.gpr.in
	${MV} ${_BOOTSTRAP_XMLADA_WRKSRC}/xmlada_shared.gpr.in \
		${_BOOTSTRAP_XMLADA_WRKSRC}/xmlada_shared.gpr

pre-build:
	@${ECHO_MSG} "*** pre-build target (1):"
	@${ECHO_MSG} "*** Build (gnatmake & sh) bootstrap GPRBuild with \"bundled\" XML/Ada and GPR"
	@${ECHO_MSG} "*** knowledge base (KB) in ${_BOOTSTRAP_WRKDIR}."
	${MKDIR} ${_BOOTSTRAP_WRKDIR}
	(cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${_BOOTSTRAP_GNATMAKE_FLAGS} \
		./bootstrap.sh --build --prefix=${_BOOTSTRAP_PREFIX} \
		--with-kb=${WRKDIR}/gprconfig_kb-${DISTVERSION} --with-xmlada=${_BOOTSTRAP_XMLADA_WRKSRC})
	@${ECHO_MSG} "*** pre-build target (2):"
	@${ECHO_MSG} "*** Install bootstrapped GPR tools into ${_BOOTSTRAP_PREFIX}."
	(cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${_BOOTSTRAP_GNATMAKE_FLAGS:C|-j[[:digit:]]||} \
		./bootstrap.sh --install --prefix=${_BOOTSTRAP_PREFIX} \
		--with-kb=${WRKDIR}/gprconfig_kb-${DISTVERSION} --with-xmlada=${_BOOTSTRAP_XMLADA_WRKSRC})
	@${ECHO_MSG} "*** pre-build target (3):"
	@${ECHO_MSG} "*** Configure GPRBuild (gprconfig) with the used GNAT-${_ada_version} tool-chain."
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV:C|PATH=|PATH=${_BOOTSTRAP_PATH}:|} \
		gprconfig --batch --target=${CONFIGURE_TARGET} --config=Ada,,default,${LOCALBASE}/gnat${_ada_version}/bin,GNAT)
	@${ECHO_MSG} "*** pre-build target (4):"
	@${ECHO_MSG} "*** Build (gprbuild) \"bundled\" XML/Ada with bootstrapped tools."
. for _library_type in ${_BOOTSTRAP_XMLADA_LIBRARY_TYPES}
	(cd ${_BOOTSTRAP_XMLADA_WRKSRC} && \
		${SETENV} ${MAKE_ENV:C|PATH=|PATH=${_BOOTSTRAP_PATH}:|} \
		${MAKE_CMD} ${_BOOTSTRAP_XMLADA_GPRBUILD_ARGS} -XLIBRARY_TYPE=${_library_type} \
		-P xmlada)
. endfor
	@${ECHO_MSG} "*** pre-build target (5):"
	@${ECHO_MSG} "*** Install (gprinstall) \"bundled\" XML/Ada with bootstrapped tools"
	@${ECHO_MSG} "*** into ${_BOOTSTRAP_PREFIX}."
. for _xmlada_component in dom sax schema unicode
.  for _library_type in ${_BOOTSTRAP_XMLADA_LIBRARY_TYPES}
	(cd ${_BOOTSTRAP_XMLADA_WRKSRC} && \
		${SETENV} ${MAKE_ENV:C|PATH=|PATH=${_BOOTSTRAP_PATH}:|} \
		gprinstall ${_BOOTSTRAP_XMLADA_GPRINSTALL_ARGS} --ali-subdir=libdata/xmlada/${_library_type} \
		--build-name=${_library_type} --build-var=${_library_type} \
		--lib-subdir=lib/xmlada/${_xmlada_component}/${_library_type} \
		--sources-subdir=include/xmlada/${_xmlada_component} \
		-XLIBRARY_TYPE=${_library_type} -P ${_xmlada_component}/xmlada_${_xmlada_component})
.  endfor
. endfor
. for _library_type in ${_BOOTSTRAP_XMLADA_LIBRARY_TYPES}
	(cd ${_BOOTSTRAP_XMLADA_WRKSRC} && \
		${SETENV} ${MAKE_ENV:C|PATH=|PATH=${_BOOTSTRAP_PATH}:|} \
		gprinstall ${_BOOTSTRAP_XMLADA_GPRINSTALL_ARGS} --ali-subdir=libdata/xmlada/${_library_type} \
		--build-name=${_library_type} --build-var=${_library_type} \
		--lib-subdir=lib/xmlada/input/${_library_type} --sources-subdir=include/xmlada/input \
		-XLIBRARY_TYPE=${_library_type} -P input_sources/xmlada_input)
. endfor
	@${ECHO_MSG} "*** pre-build target:"
	@${ECHO_MSG} "*** Bootstrapping complete."

do-build:
	@${ECHO_MSG} "*** do-build target (6):"
	@${ECHO_MSG} "*** Final build stage."
	@${ECHO_MSG} "*** Build GPR Tools with bootstrapped gprbuild."
. for _library_type in ${_GPRBUILD_LIBRARY_TYPES}
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV:C|PATH=|PATH=${_BOOTSTRAP_PATH}:|} \
		gprbuild ${_FINAL_STAGE_GPRBUILD_ARGS} -XLIBRARY_TYPE=${_library_type} \
		-P ${PORTNAME})
. endfor
	@${ECHO_MSG} "*** do-build target (7):"
	@${ECHO_MSG} "*** Final build stage."
	@${ECHO_MSG} "*** Build libgpr with bootstrapped gprbuild."
. for _library_type in ${_LIBGPR_LIBRARY_TYPES}
	(cd ${WRKSRC}/gpr && \
		${SETENV} ${MAKE_ENV:C|PATH=|PATH=${_BOOTSTRAP_PATH}:|} \
		${MAKE_CMD} ${_FINAL_STAGE_LIBGPR_BUILD_ARGS} -XLIBRARY_TYPE=${_library_type} \
		-P gpr ${_LIBGPR_GPRBUILD_CARGS})
. endfor
	@${ECHO_MSG} "*** do-build target:"
	@${ECHO_MSG} "*** Final build stage complete."
	(cd ${WRKSRC}/doc && \
		${SETENV} ${MAKE_ENV} sphinx-build-${PYTHON_VER} -c ./share \
		-d ./doctrees -b man . build/man)

do-build-DOCS-on:
	(cd ${WRKSRC}/doc && \
		${SETENV} ${MAKE_ENV} sphinx-build-${PYTHON_VER} -c ./share \
		-d ./doctrees -b html . build/html)

do-install:
	@${ECHO} "*** do-install target (8):"
	@${ECHO} "*** Installation of GPRBuild."
. for _library_type in ${_GPRBUILD_LIBRARY_TYPES}
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV:C|PATH=|PATH=${_BOOTSTRAP_PATH}:|} \
		gprinstall ${_FINAL_STAGE_GPRINSTALL_ARGS} --ali-subdir=libdata/${PORTNAME}/${_library_type} \
		--build-name=${_library_type} --build-var=${_library_type} \
		--lib-subdir=lib/${PORTNAME}/${_library_type} --sources-subdir=include/${PORTNAME} \
		-XLIBRARY_TYPE=${_library_type} -P ${PORTNAME})
. endfor
	@${ECHO} "*** do-install target (9):"
	@${ECHO} "*** Installation of libgpr."
. for _library_type in ${_LIBGPR_LIBRARY_TYPES}
	(cd ${WRKSRC}/gpr && \
		${SETENV} ${MAKE_ENV:C|PATH=|PATH=${_BOOTSTRAP_PATH}:|} \
		gprinstall ${_FINAL_STAGE_LIBGPR_INSTALL_ARGS} --ali-subdir=libdata/${PORTNAME}/gpr/${_library_type} \
		--build-name=${_library_type} --build-var=${_library_type} \
		--lib-subdir=lib/${PORTNAME}/gpr/${_library_type} --sources-subdir=include/${PORTNAME}/gpr \
		-XLIBRARY_TYPE=${_library_type} -P gpr)
. endfor
	${INSTALL_MAN} ${WRKSRC}/doc/build/man/gprtoolsusersguide.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${FIND} ${STAGEDIR}${PREFIX}/bin -name gpr* -exec ${STRIP_CMD} {} \
		\;
	${FIND} ${STAGEDIR}${PREFIX}/lib* -name *.a -exec ${STRIP_CMD} {} \
		\;
	${FIND} ${STAGEDIR}${PREFIX}/lib* -name *.so* -exec ${STRIP_CMD} \
		{} \;
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${MV} ${STAGEDIR}${PREFIX}/bin/gprbind \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${MV} ${STAGEDIR}${PREFIX}/bin/gprlib \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${RM} ${STAGEDIR}${PREFIX}/doinstall

do-install-DOCS-on:
	(cd ${WRKSRC}/doc/build/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} ${_DOCS_INSTALL_EXCLUDES})

post-install-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
