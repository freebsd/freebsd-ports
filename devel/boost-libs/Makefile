# Ports collection makefile for:  boost-libs
# Date Created:			  30 April 2009
# Whom:				  Alexander Churanov <churanov.port.maintainer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	boost-libs
PORTREVISION=	1
COMMENT=	Free portable C++ libraries (without Boost.Python)
USE_BZIP2=	yes

BUILD_DEPENDS+=	bjam:${PORTSDIR}/devel/boost-jam

OPTIONS=	VERBOSE_BUILD	"Show compiler messages"	off \
		DEBUG		"Build debugging symbols"	off \
		ICU		"Boost.Regex with ICU unicode support" on \
		OPTIMIZED_CFLAGS "Enable -O3 optimization"	off

BOOST_LIBS=	date_time filesystem graph iostreams\
		math_c99 math_c99f math_tr1 math_tr1f\
		prg_exec_monitor program_options regex\
		serialization signals system thread unit_test_framework\
		wave wserialization

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/boost-all/common.mk"
.include "${PORTSDIR}/devel/boost-all/compiled.mk"

.if defined (WITH_ICU)
LIB_DEPENDS+=	icuuc:${PORTSDIR}/devel/icu
BJAM_OPTIONS+=	-sICU_PATH=${LOCALBASE}
.endif

post-patch: customize-boost-build
# The following directory is empty and causes issues with pkg_{add,delete}
	${RMDIR} ${WRKSRC}/boost/interprocess/containers/detail
# Remove Boost.Python
	${RM} -rf ${WRKSRC}/boost/python* ${WRKSRC}/libs/python
# Add symlink to help build system to find random_device.cpp
	${LN} -s ${WRKSRC}/libs/random/src/random_device.cpp ${WRKSRC}/libs/random/random_device.cpp

do-build:
# build the library
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_OPTIONS} --prefix=${PREFIX}\
		--toolset=${BOOST_TOOLS}

# build bgl-viz library
	cd ${WRKSRC}/libs/graph/build && \
		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_OPTIONS} --prefix=${PREFIX}\
		--toolset=${BOOST_TOOLS}

# build random device code
	cd ${WRKSRC}/libs/random && \
	${CXX} ${CXXCFLAGS} ${CFLAGS} -c -I${WRKSRC} random_device.cpp && \
	${AR} rc ${WRKSRC}/bin.v2/libs/libboost_random.a random_device.o

do-install:
# Install libraries
	${FIND} ${WRKSRC}/bin.v2/libs -type f -name "*.a"\
		-exec ${INSTALL_DATA} \{\} ${PREFIX}/lib \;

	${FIND} -E ${WRKSRC}/bin.v2/libs -type f \
		-regex '.*so' \
		-exec ${INSTALL_DATA} \{\} ${PREFIX}/lib \;

# Create symlinks for shared libraries
.for lib in ${BOOST_LIBS}
	cd ${PREFIX}/lib && \
	${MV} "libboost_${lib}.so" "libboost_${lib}.so.${BOOST_SHARED_LIB_VER}" && \
	${LN} -fs "libboost_${lib}.so.${BOOST_SHARED_LIB_VER}" "libboost_${lib}.so"
.endfor

# Install headers
	cd ${WRKSRC} && \
	${FIND} boost -type d -a \! -name "*.orig"\
		-exec ${MKDIR} ${PREFIX}/include/\{\} \;

	cd ${WRKSRC} && \
	${FIND} boost -type f -a \! -name "*.orig"\
		-exec ${INSTALL_DATA} \{\} ${PREFIX}/include/\{\} \;

# display pkg-message
post-install:
	@${TOUCH} ${PKGMESSAGE}

	@${CAT} ${PKG_MESSAGE_FILE_THREADS} >> ${PKGMESSAGE}
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
