# Created by: Alexander Churanov <churanov.port.maintainer@gmail.com>
# $FreeBSD$

PORTNAME=	boost-python-libs
COMMENT=	Framework for interfacing Python and C++

USE_PYTHON=	yes

OPTIONS_DEFINE=	VERBOSE_BUILD DEBUG OPTIMIZED_CFLAGS
VERBOSE_BUILD_DESC=	Show compiler messages

.include "${.CURDIR}/../boost-all/common.mk"

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/boost-all/compiled.mk"

.if ${ARCH} == "sparc64"
CXXFLAGS=	-O0
.endif

MAKE_ENV+=	PYTHON_ROOT="${LOCALBASE}"\
		PYTHON_VERSION="${PYTHON_VERSION}"\
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}"\
		PYTHON_LIB_PATH="${PYTHON_LIBDIR}"

RUN_DEPENDS+=	${LOCALBASE}/lib/libboost_thread.so.${BOOST_SHARED_LIB_VER}:${PORTSDIR}/devel/boost-libs

BUILD_DEPENDS+=	${BJAM}:${PORTSDIR}/devel/boost-jam

do-build:
	@${ECHO_CMD} "using python : " ${PYTHON_VER} " : " ${PYTHON_CMD} " : " ${PYTHON_INCLUDEDIR} ";" >> ${WRKSRC}/tools/build/v2/site-config.jam
# build the library
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_ARGS} --with-python stage
	@cd ${WRKSRC}/stage/lib && \
		( for l in lib*.so.*; do ${LN} -sf $${l} $${l%.*}; done )

do-install:
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p libboost* ${PREFIX}/lib
# For some reasons BJAM forget about the links
	@cd ${WRKSRC}/stage/ && ${FIND} lib -type l | ${PAX} -rw -p p ${PREFIX}

post-install:
# display pkg-message
	@${TOUCH} ${PKGMESSAGE}
	@${CAT} ${PKG_MESSAGE_FILE_THREADS} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}
	@${CAT} ${PKG_MESSAGE_FILE_PYTHON} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}
	@${REINPLACE_CMD} \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g" \
		-e "s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g" \
		-e "s|%%PYTHON_LIBDIR%%|${PYTHON_LIBDIR}|g" \
		-e "s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|g" ${PKGMESSAGE}
	@if [ -s ${PKGMESSAGE} ]; then \
		${CAT} ${PKGMESSAGE}; \
	fi

.include <bsd.port.post.mk>
