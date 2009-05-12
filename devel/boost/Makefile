# ex:ts=8
# Ports collection makefile for:  boost
# Date Created:			  6 January 2002
# Whom:				  Paul Marquis <pmarquis@pobox.com>
#
# $FreeBSD$

PORTNAME=	boost
PORTVERSION=	1.37.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SOURCEFORGE
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	churanov.port.maintainer@gmail.com
COMMENT=	Free peer-reviewed portable C++ source libraries

USE_BZIP2=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/./_/g}

.if defined(WITH_PYTHON) || defined (WITH_PYSTE)
USE_PYTHON=	2.4+

CONFLICTS=	boost-1*

# Python implies threads
WITH_THREADS=IMPLIED_BY_PYTHON
.else
CONFLICTS=	boost-python-1*
.endif

OPTIONS=	VERBOSE_BUILD	"Show compiler messages"	off \
		DEBUG		"Build debugging symbols"	off \
		THREADS		"Thread support"		on  \
		ICU		"Boost.Regex with ICU unicode support" off \
		OPTIMIZED_CFLAGS "Enable -O3 optimization"	off

UNIQ=		/usr/bin/uniq
BOOST_LIBS=	date_time filesystem graph iostreams \
		math_c99 math_c99f math_tr1 math_tr1f \
		prg_exec_monitor program_options regex \
		serialization signals system unit_test_framework \
		wave wserialization

BOOST_SHARED_LIB_VER=	4

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if !defined(WITH_PYTHON) && defined(WITH_PYSTE)
WITH_PYTHON=	IMPLIED_BY_PYSTE
.endif

#
# Unfortunately, it is not possible to use OPTIONS to control the
# optional Python support
#
# In order to build Boost's Python bindings, please specify
# -DWITH_PYTHON on the command line or use the devel/boost-python
# slave port.
#
# To build Pyste, the Boost.Python code generator use -DWITH_PYSTE
# (this implies -DWITH_PYTHON).
#
.if defined(WITH_PYTHON)
PKGNAMESUFFIX=	-python
PLIST_SUB+=	BOOST_PYTHON="" \
		PYTHON_VER=${PYTHON_VER}
MAKE_ENV+=	PYTHON_ROOT="${LOCALBASE}" \
		PYTHON_VERSION="${PYTHON_VERSION}" \
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}" \
		PYTHON_LIB_PATH="${PYTHON_LIBDIR}"
BOOST_LIBS+=	python

. if defined(WITH_PYSTE)
RUN_DEPENDS+=	gccxml:${PORTSDIR}/devel/gccxml \
		${PYTHON_SITELIBDIR}/elementtree/ElementTree.py:${PORTSDIR}/devel/py-elementtree
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/ElementTree.py:${PORTSDIR}/devel/py-elementtree
PLIST_SUB+=	BOOST_PYSTE=""
. else
PLIST_SUB+=	BOOST_PYSTE="@comment "
. endif
.else
PLIST_SUB+=	BOOST_PYTHON="@comment "
PLIST_SUB+=	BOOST_PYSTE="@comment "
.endif

# Bjam configuratation
BOOST_TOOLS=	gcc

BJAM_OPTIONS=	--layout=system
BJAM_OPTIONS+=	${_MAKE_JOBS}
.if defined (WITH_VERBOSE_BUILD)
BJAM_OPTIONS+=	-d2
.endif

.if defined (WITH_ICU)
LIB_DEPENDS+=	icuuc:${PORTSDIR}/devel/icu
BJAM_OPTIONS+=	-sICU_PATH=${LOCALBASE}
.endif

.if defined (WITHOUT_DEBUG)
BJAM_OPTIONS+=	variant=release
.else
BJAM_OPTIONS+=	variant=debug
.endif

.if defined (WITHOUT_THREADS) && ! defined (WITH_PYTHON)
BJAM_OPTIONS+=	threading=single
PLIST_SUB+=	BOOST_THREADS="@comment "
.else
BJAM_OPTIONS+=	threading=multi
PLIST_SUB+=	BOOST_THREADS=""
BOOST_LIBS+=	thread
.endif

# Unless WITH_OPTIMIZED_CFLAGS is defined, the port uses
# CXXFLAGS as defined by the user (overridng Boost's 'speed'
# configuration scheme
BJAM_OPTIONS+=	optimization=speed
.if defined (WITH_OPTIMIZED_CFLAGS)
BJAM_OPTIONS+=	inlining=full
CXXFLAGS=	-O3
.endif

.if ${ARCH} == alpha
BJAM=		${WRKSRC}/tools/jam/src/bin.freebsdaxp/bjam
.elif ${ARCH} == sparc64
BJAM=		${WRKSRC}/tools/jam/src/bin.freebsdsparc/bjam
.elif ${ARCH} == ia64
BJAM=		${WRKSRC}/tools/jam/src/bin.freebsdia64/bjam
.elif ${ARCH} == powerpc
BJAM=		${WRKSRC}/tools/jam/src/bin.freebsdppc/bjam
.elif ${ARCH} == i386
BJAM=		${WRKSRC}/tools/jam/src/bin.freebsdx86/bjam
.elif ${ARCH} == amd64
BJAM=		${WRKSRC}/tools/jam/src/bin.freebsdx86_64/bjam
.else
BJAM=		${WRKSRC}/tools/jam/src/bin.freebsd/bjam
.endif

# Handle python settings
pre-everything::
.if !defined(WITH_PYTHON)
	@${ECHO_CMD}
	@${ECHO_CMD} To build Boost\'s Python bindings hit CTRL+C now and
	@${ECHO_CMD} run \`\`make -DWITH_PYTHON [...]\'\' or use the
	@${ECHO_CMD} devel/boost-python slave port.
	@${ECHO_CMD}
	@sleep 2
.else
.if ${WITH_PYTHON} == IMPLIED_BY_PYSTE
	@${ECHO_CMD}
	@${ECHO_CMD} WITH_PYSTE implies WITH_PYTHON! Enabling Python bindings!
	@${ECHO_CMD}
.else
	@${ECHO_CMD}
	@${ECHO_CMD} Python bindings enabled!
	@${ECHO_CMD}
.endif
.if !defined(WITH_PYSTE)
	@${ECHO_CMD} To build Pyste, Boost.Python\'s interface generator,  hit CTRL+C now and
	@${ECHO_CMD} run \`\`make -DWITH_PYTHON -DWITH_PYSTE[...]\'\'.
	@${ECHO_CMD}
	@sleep 2
.else
	@${ECHO_CMD} Pyste will be installed!
	@${ECHO_CMD}
.endif
.endif

post-patch:
# If necessary, remove Boost.Python
.if !defined(WITH_PYTHON)
	@${RM} -rf ${WRKSRC}/boost/python* ${WRKSRC}/libs/python
.endif

# Do the right thing(tm) for pthread support and respect CXX
	@${REINPLACE_CMD}\
		-e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|' \
		-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
		-e 's|%%CXX%%|${CXX}|' \
		-e 's|%%CXXFLAGS%%|${CXXFLAGS}|' \
	${WRKSRC}/tools/build/v2/tools/gcc.jam

	@${REINPLACE_CMD}\
		-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS:S/-//}|' \
	${WRKSRC}/tools/build/v2/tools/python.jam

post-configure:
# Configure pyste, the Boost.Python code generator
.if defined(WITH_PYSTE)
	@cd ${BUILD_WRKSRC}/libs/python/pyste/install && \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} \
		config ${PYDISTUTILS_CONFIGUREARGS}
.endif

do-build:
# build the bjam project build tool
	cd ${WRKSRC}/tools/jam/src && ./build.sh gcc;

# build the library
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_OPTIONS} --prefix=${PREFIX} \
		--toolset=${BOOST_TOOLS}

# build bgl-viz library
	cd ${WRKSRC}/libs/graph/build && \
		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_OPTIONS} --prefix=${PREFIX} \
		--toolset=${BOOST_TOOLS}

# build random device code
	cd ${WRKSRC}/libs/random && \
	${CXX} ${CXXCFLAGS} ${CFLAGS} -c -I${WRKSRC} random_device.cpp && \
	${AR} rc ${WRKSRC}/bin.v2/libs/libboost_random.a random_device.o

# Build pyste, the Boost.Python code generator
.if defined(WITH_PYSTE)
	cd ${BUILD_WRKSRC}/libs/python/pyste/install && \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} \
		build ${PYDISTUTILS_BUILDARGS}
.endif

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BJAM} ${PREFIX}/bin/

# Install libraries
	${MKDIR} ${PREFIX}/lib
	${FIND} ${WRKSRC}/bin.v2/libs -type f -name "*.a" \
		-exec ${INSTALL_DATA} \{\} ${PREFIX}/lib \;

	${FIND} ${WRKSRC}/bin.v2/libs -type f \
		-name "*.so" \
		-exec ${INSTALL_DATA} \{\} ${PREFIX}/lib \;

# Create symlinks for shared libraries
.for lib in ${BOOST_LIBS}
	cd ${PREFIX}/lib && \
	${MV} -f "libboost_${lib}.so" "libboost_${lib}.so.${BOOST_SHARED_LIB_VER}" && \
	${LN} -fs "libboost_${lib}.so.${BOOST_SHARED_LIB_VER}" "libboost_${lib}.so"
.endfor

# Install headers
	${MKDIR} ${PREFIX}/include
	cd ${WRKSRC} && \
	${FIND} boost -type d -a \! -name "*.orig" \
		-exec ${MKDIR} ${PREFIX}/include/\{\} \;

	cd ${WRKSRC} && \
	${FIND} boost -type f -a \! -name "*.orig" \
		-exec ${INSTALL_DATA} \{\} ${PREFIX}/include/\{\} \;

# Install pyste, the Boost.Python code generator
.if defined(WITH_PYSTE)
	cd ${WRKSRC}/libs/python/pyste/install && \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} \
		install ${PYDISTUTILS_INSTALLARGS}
.else
# Delete pyste folder in order not to install the documentation
	${RM} -rf ${WRKSRC}/libs/python/pyste
.endif

# Documentation & examples
.if !defined(NOPORTDOCS)
# Installation
	${MKDIR} ${DOCSDIR}

	${FIND} ${WRKSRC} -type f -exec ${CHMOD} 0444 {} \;
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 {} \;
	${FIND} ${WRKSRC} -name ".cvsignore" -delete
	cd ${WRKSRC} && \
	${FIND} . -name "*.htm" -o -name "*.html"  -o -name "*.css" \
		-o -name "*.jp*g" -o -name "*.png" -o -name "*.gif" \
		| ${TAR} cTf - - | ${TAR} xUCf ${DOCSDIR} -

	cd ${WRKSRC}/libs && \
	${FIND} . -name "example" -o -name "examples" -o -name "*example*.cpp" \
		-o -name "*example*.c" -o -name "*example*.hpp" | ${UNIQ} | \
		${GREP} -v "assign/test" | ${GREP} -v "iterator/test" | \
		${GREP} -v "range/test" | \
	${TAR} cTf - - | ${TAR} xUCf ${DOCSDIR}/libs -
.endif

# display pkg-message
post-install:
	@${TOUCH} ${PKGMESSAGE}

.if defined (WITH_THREADS)
	@${CAT} ${.CURDIR}/../boost/pkg-message.threads >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}
.endif

.if defined (WITH_PYTHON)
	@${CAT} ${.CURDIR}/../boost/pkg-message.python >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}
.endif

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
