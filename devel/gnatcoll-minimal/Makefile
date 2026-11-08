PORTNAME=	gnatcoll-core
DISTVERSION=	26.2
CATEGORIES=	devel lang
PKGNAMESUFFIX=	-minimal

MAINTAINER=	ada@FreeBSD.org
COMMENT=	GNAT Components Collection (Minimal)
WWW=		https://docs.adacore.com/live/wave/gnatcoll-core/html/gnatcoll-core_ug/minimal/index.html

LICENSE=	GPLv3+ GPLv3RLE+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING3
LICENSE_FILE_GPLv3RLE+ =	${WRKSRC}/COPYING.RUNTIME

BUILD_DEPENDS=	gprbuild>0:devel/gprbuild

USES=		ada:run
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore

MAKE_CMD=	gprbuild

NO_SHLIB_REQUIRES_GLOB=	libgnarl-${_ada_version}.so libgnat-${_ada_version}.so

CONFLICTS=	gnatcoll-core

EXTRACT_AFTER_ARGS=	${_DIST_EXCLUDES:S,^,--exclude ,}

PLIST_SUB=	SO_DISTVERSION=${DISTVERSION} \
		SO_VERSION=${DISTVERSION:R}

_DIST_EXCLUDES=		./gprproject ./projects ./testsuite .als.json .git* \
			alire.toml CONTRIBUTING.md distrib Makefile
_DOCS_INSTALL_EXCLUDES=	"-not -name .buildinfo -not -regex ^./_sources.*"
_GPRBUILD_ARGS=		${_GPR_PROJECT_ARGS} -j${MAKE_JOBS_NUMBER} -p -vh -vP2
_GPRINSTALL_ARGS=	${_GPR_PROJECT_ARGS} --no-manifest \
			--prefix='${STAGEDIR}${PREFIX}' -p -v
_GPR_LIBRARY_TYPES=	relocatable static static-pic
_GPR_PROJECT_ARGS=	-XGNATCOLL_BUILD_MODE=${WITH_DEBUG:UPROD:DDEBUG} \
			-XGNATCOLL_VERSION=${DISTVERSION}
_GPR_PROJECT=		${PORTNAME:C/-.*//}${PKGNAMESUFFIX:C/-/_/}
_GPR_SUBDIR=		${PORTNAME:C,-core,/,}${PKGNAMESUFFIX:C/-//}

do-build:
. for _library_type in ${_GPR_LIBRARY_TYPES}
	(cd ${WRKSRC}/minimal && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_GPRBUILD_ARGS} -XLIBRARY_TYPE=${_library_type} \
		-P ${_GPR_PROJECT})
. endfor

do-install:
. for _library_type in ${_GPR_LIBRARY_TYPES}
	(cd ${WRKSRC}/minimal && \
		${SETENV} ${MAKE_ENV} gprinstall ${_GPRINSTALL_ARGS} --ali-subdir=libdata/${_GPR_SUBDIR}/${_library_type} \
		--build-name=${_library_type} --build-var=${_library_type} \
		--lib-subdir=lib/${_GPR_SUBDIR}/${_library_type} --sources-subdir=include/${_GPR_SUBDIR} \
		-XLIBRARY_TYPE=${_library_type} -P ${_GPR_PROJECT})
. endfor
	${FIND} ${STAGEDIR}${PREFIX}/lib -name *.a -exec ${STRIP_CMD} {} \
		\;
	${FIND} ${STAGEDIR}${PREFIX}/lib -name *.so.${DISTVERSION} -exec \
		${STRIP_CMD} {} \;

.include <bsd.port.mk>
