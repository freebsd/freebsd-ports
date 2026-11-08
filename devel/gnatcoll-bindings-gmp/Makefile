PORTNAME=	gnatcoll-bindings
DISTVERSION=	26.2
CATEGORIES=	devel lang math science
PKGNAMESUFFIX=	-gmp

MAINTAINER=	ada@FreeBSD.org
COMMENT=	GNATColl interface to GNU Multiple Precision arithmetic library
WWW=		https://github.com/AdaCore/gnatcoll-bindings

LICENSE=	GPLv3+ GPLv3RLE+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING3
LICENSE_FILE_GPLv3RLE+ =	${WRKSRC}/COPYING.RUNTIME

BUILD_DEPENDS=	gprbuild>0:devel/gprbuild
LIB_DEPENDS=	libgmp.so:math/gmp \
		libgnatcoll_minimal.so:devel/gnatcoll-core

USES=		ada:run
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore

MAKE_CMD=	gprbuild

NO_SHLIB_REQUIRES_GLOB=	libgnarl-${_ada_version}.so libgnat-${_ada_version}.so

EXTRACT_AFTER_ARGS=	${_DIST_EXCLUDES:S,^,--exclude ,}

PLIST_SUB=	SO_DISTVERSION=${DISTVERSION} \
		SO_VERSION=${DISTVERSION:R}

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

_DIST_DOCS=		doc* version_information
_DIST_GCB_COMPONENTS=	cpp iconv lzma omp python python3 readline syslog zlib \
			zstd
_DIST_TESTING=		test*
_DIST_EXCLUDES=		${_DIST_DOCS} ${_DIST_GCB_COMPONENTS} ${_DIST_TESTING} \
			.git* gen_gps_help.py gnat_debug.adc gprproject \
			README.md setup.py setup_support.py
_GCB_COMPONENT_DIR=	${PKGNAMESUFFIX:S/-//}
_GCB_COMPONENT_GPR=	${PORTNAME:C/-.*//}_${PKGNAMESUFFIX:S/-//}
_GPRBUILD_ARGS=		${_GPR_PROJECT_ARGS} -j${MAKE_JOBS_NUMBER} -p -vh -vP2
_GPRINSTALL_ARGS=	${_GPR_PROJECT_ARGS} --no-manifest \
			--prefix='${STAGEDIR}${PREFIX}' -p -v
_GPR_LIBRARY_TYPES=	relocatable static static-pic
_GPR_PROJECT_ARGS=	-XGNATCOLL_BUILD_MODE=${WITH_DEBUG:UPROD:DDEBUG} \
			-XGNATCOLL_VERSION=${DISTVERSION}
_GPR_SUBDIR=		${PORTNAME:C,-bindings,/,}${PKGNAMESUFFIX:C/-//}

do-build:
. for _library_type in ${_GPR_LIBRARY_TYPES}
	(cd ${WRKSRC}/${_GCB_COMPONENT_DIR} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_GPRBUILD_ARGS} -XLIBRARY_TYPE=${_library_type} \
		-P ${_GCB_COMPONENT_GPR})
. endfor

do-install:
. for _library_type in ${_GPR_LIBRARY_TYPES}
	(cd ${WRKSRC}/${_GCB_COMPONENT_DIR} && \
		${SETENV} ${MAKE_ENV} gprinstall ${_GPRINSTALL_ARGS} --ali-subdir=libdata/${_GPR_SUBDIR}/${_library_type} \
		--build-name=${_library_type} --build-var=${_library_type} \
		--lib-subdir=lib/${_GPR_SUBDIR}/${_library_type} --sources-subdir=include/${_GPR_SUBDIR} \
		-XLIBRARY_TYPE=${_library_type} -P ${_GCB_COMPONENT_GPR})
. endfor
	${FIND} ${STAGEDIR}${PREFIX}/lib -name *.a -exec ${STRIP_CMD} {} \
		\;
	${FIND} ${STAGEDIR}${PREFIX}/lib -name *.so* -exec ${STRIP_CMD} \
		{} \;

post-install-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${EXAMPLESDIR:C/-bindings.*//}

.include <bsd.port.mk>
