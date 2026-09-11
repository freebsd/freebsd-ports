PORTNAME=	gnatcoll-core
DISTVERSION=	26.2
CATEGORIES=	devel lang

MAINTAINER=	ada@FreeBSD.org
COMMENT=	GNAT Components Collection (Core and Minimal)
WWW=		https://docs.adacore.com/live/wave/gnatcoll-core/html/gnatcoll-core_ug/index.html

LICENSE=	GPLv3+ GPLv3RLE+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING3
LICENSE_FILE_GPLv3RLE+ =	${WRKSRC}/COPYING.RUNTIME

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
		gprbuild>0:devel/gprbuild \
		sphinx-build:textproc/py-sphinx@${PY_FLAVOR}

USES=		ada:run python:build
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore

MAKE_CMD=	gprbuild

NO_SHLIB_REQUIRES_GLOB=	libgnarl-${_ada_version}.so libgnat-${_ada_version}.so

CONFLICTS=	gnatcoll-minimal

EXTRACT_AFTER_ARGS=	${_DIST_EXCLUDES:S,^,--exclude ,}

PLIST_SUB=	SO_DISTVERSION=${DISTVERSION} \
		SO_VERSION=${DISTVERSION:R}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

EXAMPLES_DESC=	Install GNATColl Core examples

_DIST_EXCLUDES=		./gprproject ./projects ./testsuite .als.json .git* \
			alire.toml CONTRIBUTING.md distrib Makefile
_DOCS_INSTALL_EXCLUDES=	"-not -name .buildinfo -not -regex ^./_sources.*"
_GPRBUILD_ARGS=		${_GPR_PROJECT_ARGS} -j${MAKE_JOBS_NUMBER} -p -vh -vP2
_GPRINSTALL_ARGS=	${_GPR_PROJECT_ARGS} --no-manifest \
			--prefix='${STAGEDIR}${PREFIX}' -p -v
_GPR_LIBRARY_TYPES=	relocatable static static-pic
_GPR_PROJECT_ARGS=	-aP${WRKSRC}/minimal \
			-XGNATCOLL_BUILD_MODE=${WITH_DEBUG:UPROD:DDEBUG} \
			-XGNATCOLL_VERSION=${DISTVERSION}
_GPR_PROJECT=		${PORTNAME:C/-.*/_/}
_GPR_SUBDIR=		${PORTNAME:C,-,/,}

do-build:
. for _component in core minimal
.  for _library_type in ${_GPR_LIBRARY_TYPES}
	(cd ${WRKSRC}/${_component} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_GPRBUILD_ARGS} -XLIBRARY_TYPE=${_library_type} \
		-P ${_GPR_PROJECT}${_component})
.  endfor
. endfor
	(cd ${WRKSRC}/docs && \
		${SETENV} ${MAKE_ENV} sphinx-build-${PYTHON_VER} -b man \
		. -d ./doctrees build/man)

post-build-DOCS-on:
	(cd ${WRKSRC}/docs && \
		${SETENV} ${MAKE_ENV} sphinx-build-${PYTHON_VER} -b man \
		. -d ./doctrees build/html)

do-install:
. for _component in core minimal
.  for _library_type in ${_GPR_LIBRARY_TYPES}
.    if ${_component} == minimal
	(cd ${WRKSRC}/${_component} && \
		${SETENV} ${MAKE_ENV} gprinstall ${_GPRINSTALL_ARGS} --ali-subdir=libdata/${_GPR_SUBDIR}/${_component}/${_library_type} \
		--build-name=${_library_type} --build-var=${_library_type} \
		--lib-subdir=lib/${_GPR_SUBDIR}/${_component}/${_library_type} \
		--sources-subdir=include/${_GPR_SUBDIR}/${_component} \
		-XLIBRARY_TYPE=${_library_type} -P ${_GPR_PROJECT}${_component})
.    else
	(cd ${WRKSRC}/${_component} && \
		${SETENV} ${MAKE_ENV} gprinstall ${_GPRINSTALL_ARGS} --ali-subdir=libdata/${_GPR_SUBDIR}/${_library_type} \
		--build-name=${_library_type} --build-var=${_library_type} \
		--lib-subdir=lib/${_GPR_SUBDIR}/${_library_type} --sources-subdir=include/${_GPR_SUBDIR}/ \
		-XLIBRARY_TYPE=${_library_type} -P ${_GPR_PROJECT}${_component})
.    endif
.  endfor
. endfor
	${INSTALL_MAN} ${WRKSRC}/docs/build/man/${PORTNAME:C|-.*||}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${FIND} ${STAGEDIR}${PREFIX}/lib -name *.a -exec ${STRIP_CMD} {} \
		\;
	${FIND} ${STAGEDIR}${PREFIX}/lib -name *.so.${DISTVERSION} -exec \
		${STRIP_CMD} {} \;

do-install-DOCS-on:
	(cd ${WRKSRC}/docs/build/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} ${_DOCS_INSTALL_EXCLUDES})

post-install-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
