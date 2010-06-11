# Ports collection makefile for:  boost-python-libs
# Date Created:			  18 March 2009
# Whom:				  Alexander Churanov <churanov.port.maintainer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	boost-python-libs
COMMENT=	Framework for interfacing Python and C++

USE_BZIP2=	yes
USE_PYTHON=	2.4+

OPTIONS=	VERBOSE_BUILD	"Show compiler messages"	off \
		DEBUG		"Build debugging symbols"	off \
		OPTIMIZED_CFLAGS "Enable -O3 optimization"	off

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/boost-all/common.mk"
.include "${PORTSDIR}/devel/boost-all/compiled.mk"

.if ${ARCH} == "sparc64"
CXXFLAGS=	-O0
.endif

MAKE_ENV+=	PYTHON_ROOT="${LOCALBASE}"\
		PYTHON_VERSION="${PYTHON_VERSION}"\
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}"\
		PYTHON_LIB_PATH="${PYTHON_LIBDIR}"

RUN_DEPENDS+=	${LOCALBASE}/lib/libboost_thread.so.${BOOST_SHARED_LIB_VER}:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/ElementTree.py:${PORTSDIR}/devel/py-elementtree

BUILD_DEPENDS+=	${BJAM}:${PORTSDIR}/devel/boost-jam
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/ElementTree.py:${PORTSDIR}/devel/py-elementtree

post-patch: customize-boost-build

do-build:
# build the library
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_OPTIONS} --prefix=${PREFIX}\
		--toolset=${BOOST_TOOLS} --with-python

# Remove non-python headers
	cd ${WRKSRC} && \
 	${FIND} boost -not -path '*boost/python*' -delete

do-install:
# Install libraries
	${FIND} ${WRKSRC}/bin.v2/libs/python -type f -name "*.a"\
 		-exec ${INSTALL_DATA} \{\} ${PREFIX}/lib \;

	${FIND} -E ${WRKSRC}/bin.v2/libs/python -type f \
 		-regex '.*so' \
		-exec ${INSTALL_DATA} \{\} ${PREFIX}/lib \;

# Create symlink for shared library
	cd ${PREFIX}/lib/ && \
	${MV} "libboost_python.so" "libboost_python.so.${BOOST_SHARED_LIB_VER}" && \
	${LN} -fs "libboost_python.so.${BOOST_SHARED_LIB_VER}" "libboost_python.so"

# Install headers
	cd ${WRKSRC} && \
	${FIND} boost -type d -a \! -name "*.orig"\
		-exec ${MKDIR} ${PREFIX}/include/\{\} \;

	cd ${WRKSRC} && \
	${FIND} boost -type f -a \! -name "*.orig"\
		-exec ${INSTALL_DATA} \{\} ${PREFIX}/include/\{\} \;

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
	${ECHO_CMD} ; \
	${ECHO_CMD} "===============================================================================" ; \
	${ECHO_CMD} ; \
	${CAT} ${PKGMESSAGE}; \
	${ECHO_CMD} "===============================================================================" ; \
	${ECHO_CMD} ; \
	fi

.include <bsd.port.post.mk>
