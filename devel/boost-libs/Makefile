PORTNAME=	boost-libs
PORTREVISION?=	1

COMMENT=	Free portable C++ libraries (without Boost.Python)
WWW=		https://www.boost.org/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

BROKEN_sparc64=	https://github.com/boostorg/context/commit/f2ef6326b6ed

BUILD_DEPENDS+=	bjam:devel/boost-jam
LIB_DEPENDS+=	libzstd.so:archivers/zstd

# Note about LLVM_FROM_PORTS option:
# Build of this port fails with assertion failure of compiler due to
# bug of LLVM/Clang in base system. The failure happens when all of
# following conditions are satisfied.
# * OSVERSION is included in either of following ranges.
#   1. 1500000 <= OSVERSION < 1500017
# * Base system is built with WITH_LLVM_ASSERTIONS variable set.
# So if your base system fulfills them you need to use LLVM ports to
# build this port.
# By default WITH_LLVM_ASSERTIONS variable is set with -CURRENT but
# not with -STABLE and -RELEASE. So whereas most -CURRENT users face
# the build failure, few -STABLE and -RELEASE user faces it.
# Therefore by default this port uses LLVM from ports only if base
# system is -CURRENT and OSVERSION is included in above ranges. It
# make it possible for most -STABLE and -RELEASE users to avoid to
# build LLVM ports unnecessarily. But if someone uses -STABLE or
# -RELEASE built with WITH_LLVM_ASSERTIONS set, then he can't build
# this port successfully on such system. So provide LLVM_FROM_PORTS
# option as a last resort for him.
OPTIONS_DEFINE=		DEBUG LLVM_FROM_PORTS OPTIMIZED_CFLAGS
OPTIONS_MULTI=		LOCALE
OPTIONS_MULTI_LOCALE=	ICONV ICU
OPTIONS_DEFAULT=	ICONV ICU
ICONV_DESC=		Boost.Locale with iconv encoding support
ICU_DESC=		Boost.Regex/Locale with ICU unicode support
LLVM_FROM_PORTS_DESC=	Use LLVM from ports to build

ICONV_USES=		iconv
ICONV_MAKE_ARGS=	-sICONV_PATH=${ICONV_PREFIX}
ICONV_MAKE_ARGS_OFF=	boost.locale.iconv=off
ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_MAKE_ARGS=		-sICU_PATH=${LOCALBASE}
ICU_MAKE_ARGS_OFF=	boost.locale.icu=off

.include "${.CURDIR}/../boost-all/common.mk"

.include "${.CURDIR}/../boost-all/compiled.mk"

MAKE_ARGS+=	--without-python
MAKE_ARGS+=	--without-mpi
MAKE_ARGS+=	${MAKE_ARGS_${CHOSEN_COMPILER_TYPE}}
MAKE_ARGS_gcc=	xdll-path=${_GCC_RUNTIME}
ALL_TARGET=	stage

# zstd compression
MAKE_ARGS+=	-sZSTD_PATH=${LOCALBASE}
MAKE_ARGS+=	-sZSTD_LIBRARY_PATH=${LOCALBASE}/lib
MAKE_ARGS+=	-sZSTD_INCLUDE=${LOCALBASE}/include


.include <bsd.port.options.mk>

# boost.stacktrace.from_exceptions is ready only for amd64 yet
.if ${ARCH:Mamd64}
PLIST_SUB+=	SFE=""
.else
MAKE_ARGS+=	boost.stacktrace.from_exception=off
PLIST_SUB+=	SFE="@comment "
.endif

.if ${ARCH:Marmv?}
pre-configure:
	${REINPLACE_CMD} -e 's,@progbits,%progbits,' \
		${WRKSRC}/boost/interprocess/interprocess_printers.hpp \
		${WRKSRC}/boost/json/detail/gdb_printers.hpp \
		${WRKSRC}/boost/outcome/experimental/status-code/status_code.hpp \
		${WRKSRC}/boost/outcome/outcome_gdb.h \
		${WRKSRC}/boost/unordered/unordered_printers.hpp \
		${WRKSRC}/libs/json/pretty_printers/generate-gdb-header.py
.endif

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_ARGS:NDESTDIR=*:S,^--prefix=,&${STAGEDIR},} ${INSTALL_TARGET}
	@${FIND} ${STAGEDIR}${PREFIX}/lib/cmake -type f -exec \
		${REINPLACE_CMD} -i '' -e 's,${STAGEDIR},,' {} +
# For some reasons BJAM forget about the links
	@cd ${WRKSRC}/stage/ && ${FIND} lib -type l | ${PAX} -rw -p p ${STAGEDIR}${PREFIX}

# display pkg-message
post-install:
	@${TOUCH} ${PKGMESSAGE}

	@${CAT} ${PKG_MESSAGE_FILE_THREADS} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}

	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

	@${REINPLACE_CMD} \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g" \
		-e "s|%%PYTHON_LIBDIR%%|${PYTHON_LIBDIR}|g" \
		-e "s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|g" ${PKGMESSAGE}

.include <bsd.port.mk>
