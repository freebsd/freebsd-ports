# Created by: Alexander Churanov <churanov.port.maintainer@gmail.com>
# $FreeBSD$

PORTNAME=	boost-libs

COMMENT=	Free portable C++ libraries (without Boost.Python)

BROKEN_sparc64=	https://github.com/boostorg/context/commit/f2ef6326b6ed

BUILD_DEPENDS+=	bjam:devel/boost-jam

OPTIONS_DEFINE=		DEBUG OPTIMIZED_CFLAGS
OPTIONS_MULTI=		LOCALE
OPTIONS_MULTI_LOCALE=	ICONV ICU
OPTIONS_DEFAULT=	ICONV ICU
ICONV_DESC=		Boost.Locale with iconv encoding support
ICU_DESC=		Boost.Regex/Locale with ICU unicode support

ICONV_USES=		iconv
ICONV_MAKE_ARGS=	-sICONV_PATH=${ICONV_PREFIX}
ICONV_MAKE_ARGS_OFF=	boost.locale.iconv=off
ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_MAKE_ARGS=		-sICU_PATH=${LOCALBASE}
ICU_MAKE_ARGS_OFF=	boost.locale.icu=off

.include "${.CURDIR}/../boost-all/common.mk"

.include "${.CURDIR}/../boost-all/compiled.mk"

MAKE_ARGS+=	--without-python
ALL_TARGET=	stage

.include <bsd.port.pre.mk>

# XXX CHOSEN_COMPILER_VERSION isn't supported, so check CXX hasn't changed
.if ${ARCH} == aarch64 && ${CXX} == c++ && \
    ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 39
BUILD_DEPENDS+=	as:devel/binutils
CFLAGS+=	-no-integrated-as
.endif

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_ARGS:NDESTDIR=*:S,^--prefix=,&${STAGEDIR},} ${INSTALL_TARGET}
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

.include <bsd.port.post.mk>
