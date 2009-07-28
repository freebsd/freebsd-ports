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
.include "${PORTSDIR}/devel/boost-all/sites.mk"
.include "${PORTSDIR}/devel/boost-all/compiled.mk"

MAKE_ENV+=	PYTHON_ROOT="${LOCALBASE}"\
		PYTHON_VERSION="${PYTHON_VERSION}"\
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}"\
		PYTHON_LIB_PATH="${PYTHON_LIBDIR}"

RUN_DEPENDS+=	${PREFIX}/lib/libboost_thread.so.${BOOST_SHARED_LIB_VER}:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS+=	gccxml:${PORTSDIR}/devel/gccxml \
		${PYTHON_SITELIBDIR}/elementtree/ElementTree.py:${PORTSDIR}/devel/py-elementtree

BUILD_DEPENDS+=	${BJAM}:${PORTSDIR}/devel/boost-jam
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/ElementTree.py:${PORTSDIR}/devel/py-elementtree

ESCAPED_PREFIX !=	echo ${PREFIX} | sed 's/\//\\\//g'
RELATIVE_PYTHON_SITELIBDIR != echo ${PYTHON_SITELIBDIR} | sed "s/${ESCAPED_PREFIX}\///"
PLIST_SUB+=	PYTHON_SITELIBDIR=${RELATIVE_PYTHON_SITELIBDIR}
PLIST_SUB+=	PYTHON_VERSION=${PYTHON_VERSION:C/python//1}

post-patch: customize-boost-build


post-configure:
# Configure pyste, the Boost.Python code generator
	@cd ${BUILD_WRKSRC}/libs/python/pyste/install && \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} \
		config ${PYDISTUTILS_CONFIGUREARGS}

do-build:
# build the library
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_OPTIONS} --prefix=${PREFIX}\
		--toolset=${BOOST_TOOLS} --with-python

# Build pyste, the Boost.Python code generator
	cd ${BUILD_WRKSRC}/libs/python/pyste/install && \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} \
		build ${PYDISTUTILS_BUILDARGS}

# Remove non-python headers
	cd ${WRKSRC} && \
	${FIND} boost -not -path '*python*' -delete

do-install:
# Install libraries
	${INSTALL_DATA} ${WRKSRC}/bin.v2/libs/python/build/gcc-4.2.1/release/link-static/threading-multi/libboost_python.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/bin.v2/libs/python/build/gcc-4.2.1/release/threading-multi/libboost_python.so.${PORTVERSION} ${PREFIX}/lib/libboost_python.so.${BOOST_SHARED_LIB_VER}

# Create symlink for shared library
	cd ${PREFIX}/lib/ && \
	${LN} -fs "libboost_python.so.${BOOST_SHARED_LIB_VER}" "libboost_python.so"

# Install headers
	cd ${WRKSRC} && \
	${FIND} boost -type d -a \! -name "*.orig"\
		-exec ${MKDIR} ${PREFIX}/include/\{\} \;

	cd ${WRKSRC} && \
	${FIND} boost -type f -a \! -name "*.orig"\
		-exec ${INSTALL_DATA} \{\} ${PREFIX}/include/\{\} \;

# Install pyste, the Boost.Python code generator
	cd ${WRKSRC}/libs/python/pyste/install && \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} \
		install ${PYDISTUTILS_INSTALLARGS}

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
