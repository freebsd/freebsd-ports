# Created by: Alexander Churanov <churanov.port.maintainer@gmail.com>
# $FreeBSD$

PORTNAME=	boost-libs
COMMENT=	Framework for interfacing Python and C++
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

BUILD_DEPENDS=	bjam:devel/boost-jam
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		python
USE_PYTHON=	flavors

# Ignore -Wregister warnings in Python.h
CFLAGS+=	${${FLAVOR}_CFLAGS}
py27_CFLAGS=	-isystem ${PYTHON_INCLUDEDIR}

OPTIONS_DEFINE=	DEBUG OPTIMIZED_CFLAGS

.include "${.CURDIR}/../boost-all/common.mk"

.include "${.CURDIR}/../boost-all/compiled.mk"

MAKE_ENV+=	PYTHON_ROOT="${LOCALBASE}"\
		PYTHON_VERSION="${PYTHON_VERSION}"\
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}"\
		PYTHON_LIB_PATH="${PYTHON_LIBDIR}"

MAKE_ARGS+=	--with-python
ALL_TARGET=	stage

pre-build:
	@${ECHO_CMD} "using python : " ${PYTHON_VER} " : " ${PYTHON_CMD} " : " ${PYTHON_INCLUDEDIR} ";" >> ${WRKSRC}/tools/build/src/site-config.jam

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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libboost_python*.so.${PORTVERSION}

.include <bsd.port.mk>
