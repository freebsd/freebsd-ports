# Created by: Alexander Churanov <churanov.port.maintainer@gmail.com>
# $FreeBSD$

PORTNAME=	boost-python-libs
COMMENT=	Framework for interfacing Python and C++

USES+=		python

OPTIONS_DEFINE=	VERBOSE_BUILD DEBUG OPTIMIZED_CFLAGS
VERBOSE_BUILD_DESC=	Show compiler messages

.include "${.CURDIR}/../boost-all/common.mk"

.include "${.CURDIR}/../boost-all/compiled.mk"

MAKE_ENV+=	PYTHON_ROOT="${LOCALBASE}"\
		PYTHON_VERSION="${PYTHON_VERSION}"\
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}"\
		PYTHON_LIB_PATH="${PYTHON_LIBDIR}"

LIB_DEPENDS+=	libboost_thread.so:devel/boost-libs

BUILD_DEPENDS+=	${BJAM}:devel/boost-jam

do-build:
	@${ECHO_CMD} "using python : " ${PYTHON_VER} " : " ${PYTHON_CMD} " : " ${PYTHON_INCLUDEDIR} ";" >> ${WRKSRC}/tools/build/v2/site-config.jam
# build the library
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_ARGS} --with-python stage
# do not break compat yet
	@cd ${WRKSRC}/stage/lib && \
		( for l in lib*.so.*; do ${LN} -sf $${l} $${l%.${PORTVERSION}}.5; done )

do-install:
	@cd ${WRKSRC}/stage/lib && ${PAX} -rw -p p libboost* ${STAGEDIR}${PREFIX}/lib
# For some reasons BJAM forget about the links
	@cd ${WRKSRC}/stage/ && ${FIND} lib -type l | ${PAX} -rw -p p ${STAGEDIR}${PREFIX}

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

.include <bsd.port.mk>
