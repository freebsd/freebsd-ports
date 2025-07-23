PORTNAME=	boost-libs
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Framework for interfacing Python and C++
WWW=		https://www.boost.org/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

PATCHDIR=	${.CURDIR:H}/boost-libs/files

BUILD_DEPENDS=	bjam:devel/boost-jam \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libboost_container.so:devel/boost-libs

USES=		python
USE_PYTHON=	flavors

#LDFLAGS+=	-Wl,--as-needed

OPTIONS_DEFINE=	DEBUG OPTIMIZED_CFLAGS

.include "${.CURDIR:H}/boost-all/common.mk"

.include "${.CURDIR:H}/boost-all/compiled.mk"

MAKE_ENV+=	PYTHON_ROOT="${LOCALBASE}"\
		PYTHON_VERSION="${PYTHON_VERSION}"\
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}"\
		PYTHON_LIB_PATH="${PYTHON_LIBDIR}"

MAKE_ARGS+=	--with-python
#MAKE_ARGS+=	--without-container
#MAKE_ARGS+=	--without-graph
ALL_TARGET=	stage

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} == ${PYTHON_DEFAULT}
PLIST_SUB+=	PY_DEFAULT_ONLY=""
.else
PLIST_SUB+=	PY_DEFAULT_ONLY="@comment "
.endif

pre-build:
	@${ECHO_CMD} "using python : " ${PYTHON_VER} " : " ${PYTHON_CMD} " : " ${PYTHON_INCLUDEDIR} ";" >> ${WRKSRC}/tools/build/src/site-config.jam

do-install:
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p libboost_numpy* ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p libboost_python* ${STAGEDIR}${PREFIX}/lib

# CMake part
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p cmake/boost_numpy*/*-py${PYTHON_VER}.cmake ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p cmake/boost_python*/*-py${PYTHON_VER}.cmake ${STAGEDIR}${PREFIX}/lib
.if ${PYTHON_VER} == ${PYTHON_DEFAULT}
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p cmake/boost_numpy*/*-config*.cmake ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p cmake/boost_python*/*-config*.cmake ${STAGEDIR}${PREFIX}/lib
.endif
	@${FIND} ${STAGEDIR}${PREFIX}/lib/cmake -type f -exec \
		${REINPLACE_CMD} -i '' -e 's,${STAGEDIR},,' {} +

post-install:
# display pkg-message
	@${TOUCH} ${PKGMESSAGE}
	@${CAT} ${PKG_MESSAGE_FILE_THREADS} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}
	@${CAT} ${PKG_MESSAGE_FILE_PYTHON} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}
	@${REINPLACE_CMD} \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g" \
		-e "s|%%PYTHON_LIBDIR%%|${PYTHON_LIBDIR}|g" \
		-e "s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|g" ${PKGMESSAGE}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libboost_*.so.${BOOST_SHARED_LIB_VER}

.include <bsd.port.post.mk>
