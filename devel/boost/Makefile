# ex:ts=8
# Ports collection makefile for:  boost
# Date Created:			  6 January 2002
# Whom:				  Paul Marquis <pmarquis@pobox.com>
#
# $FreeBSD$

PORTNAME=	boost
PORTVERSION=	1.32.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:boost_site,spirit_site/}
MASTER_SITE_SUBDIR=boost/:boost_site
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:boost_site

MAINTAINER=	barner@gmx.de
COMMENT=	Free peer-reviewed portable C++ source libraries

USE_BZIP2=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

MAKE_ENV+=	GCC="${CC} ${CFLAGS}"\
		GXX="${CXX} ${CXXFLAGS}"\
		STLPORT_ROOT=/

OPTIONS=	VERBOSE_BUILD	"Show compiler messages"	off \
		DEBUG		"Build debugging symbols"	off \
		THREADS		"Thread support"		on  \
		OPTIMIZED_CFLAGS "Enable -O3 optimization"	off

#
# Unfortunately, it is not possible to use OPTIONS to control the
# optional Python support
#
# In order to build Boost's Python bindings, please specify
# -DWITH_PYTHON on the command line or use the devel/boost-python
# slave port.
#
.if defined(WITH_PYTHON)
PKGNAMESUFFIX=	-python
USE_PYTHON=	2.3+
PLIST_SUB+=	BOOST_PYTHON=""
MAKE_ENV+=	PYTHON_ROOT="${LOCALBASE}"\
		PYTHON_VERSION="${PYTHON_VERSION}"\
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}"\
		PYTHON_LIB_PATH="${PYTHON_LIBDIR}"
.else
PLIST_SUB+=	BOOST_PYTHON="@comment "
.endif

.include <bsd.port.pre.mk>
SPIRIT_VERSION=	1.6.2

# FreeBSD 4:
# - no wchar support
# - needs stlport
# - spirit 1.6.x
.if ${OSVERSION} < 500000
USE_ZIP=	yes
EXTRA_PATCHES=	${FILESDIR}/FBSD4-patch-libs::serialization::build::Jamfile\
		${FILESDIR}/FBSD4-patch-boost::program_options::detail::utf8_codecvt_facet.hpp

DISTFILES+=	spirit-only-${SPIRIT_VERSION}.zip:spirit_site
MASTER_SITE_SUBDIR+=spirit/:spirit_site
BJAM_BUILD+=	<stlport-iostream>on
BOOST_TOOLS=	gcc-stlport

PLIST_SUB+=	BOOST_WCHAR="@comment "\
		BOOST_SPIRIT_1.6=""\
		BOOST_SPIRIT_1.8="@comment "

BOOST_STL_OPTS=	"-sSTLPORT_INCLUDE_DIRECTORY=${LOCALBASE}/include/stlport"\
		"-sSTLPORT_LIB_DIRECTORY=${LOCALBASE}/lib"

RUN_DEPENDS=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
BUILD_DEPENDS+=	${RUN_DEPENDS}

# FreeBSD 5
# - wchar support
# - spirit 1.8.x
.else
BOOST_TOOLS=	gcc
EXTRA_PATCHES=	${FILESDIR}/FBSD5-patch-boost::python::detail::config.hpp

PLIST_SUB+=	BOOST_WCHAR=""\
		BOOST_SPIRIT_1.6="@comment "\
		BOOST_SPIRIT_1.8=""
.endif

.if defined (WITH_VERBOSE_BUILD)
BJAM_OPTIONS=	-d2
.endif

.if defined (WITHOUT_DEBUG)
BJAM_BUILD+=	release
.else
BJAM_BUILD+=	debug
.endif

.if defined (WITHOUT_THREADS)
BJAM_BUILD+=	<threading>single
PLIST_SUB+=	BOOST_THREADS="@comment "
.else
BJAM_BUILD+=	<threading>multi
PLIST_SUB+=	BOOST_THREADS=""
.endif

.if defined (WITHOUT_OPTIMIZED_CFLAGS)
BJAM_BUILD+=	<optimization>off
.else
BJAM_BUILD+=	<optimization>speed\
		<inlining>full
.endif

.if ${ARCH} == alpha
BJAM=		${WRKSRC}/tools/build/jam_src/bin.freebsdaxp/bjam
# temporary work around for GCC bug on alpha
# ("-mcpu=ev4 -mtune=ev5 -mieee" makes gcc consume all virtual memory)
#
# If you are trying to build this on alpha, a quick test whether the problem
# still exists would be very much appreciated!
CXXFLAGS=-O -pipe
.elif ${ARCH} == sparc64
BJAM=		${WRKSRC}/tools/build/jam_src/bin.freebsdsparc/bjam
.elif ${ARCH} == ia64
BJAM=		${WRKSRC}/tools/build/jam_src/bin.freebsdia64/bjam
.else
BJAM=		${WRKSRC}/tools/build/jam_src/bin.freebsd/bjam
.endif

SCRIPTS_ENV+=	BJAM="${BJAM}"\
		NOPORTDOCS="${NOPORTDOCS}"\
		FIND="${FIND}"\
		GREP="${GREP}"\
		REINPLACE_CMD="${REINPLACE_CMD}"\
		LN="${LN}"\
		MKDIR="${MKDIR}"\
		TAR="${TAR}" \
		RM="${RM}" \
		UNIQ="/usr/bin/uniq"

.if !defined(NOPORTDOCS)
SCRIPTS_ENV+=	PORTDOCS="true"\
		DOCSDIR="${DOCSDIR}"
.endif

pre-everything::
.if !defined(WITH_PYTHON)
	@${ECHO_CMD}
	@${ECHO_CMD} To build Boost\'s Python bindings hit CTRL+C now and
	@${ECHO_CMD} run \`\`make -DWITH_PYTHON [...]\'\' or use the
	@${ECHO_CMD} devel/boost-python slave port.
	@${ECHO_CMD}
	@sleep 2
.else
	@${ECHO_CMD}
	@${ECHO_CMD} Python bindings enabled!
	@${ECHO_CMD}
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAR} -xjpof ${DISTDIR}/${DISTNAME}.tar.bz2

# boost 1.32.0's spirit 1.8.x cannot be built with GCC 2.95.4,
# so we use spirit 1.6.x
.if ${OSVERSION} < 500000
	@cd ${WRKDIR} && ${UNZIP_CMD} ${DISTDIR}/spirit-only-${SPIRIT_VERSION}.zip > /dev/null

# remove CRLF
	@${FIND} ${WRKDIR}/spirit_${SPIRIT_VERSION:S/./_/g} -type f -exec \
		${REINPLACE_CMD} -i '' -e "s|"`printf '\015'`"||g" {} \;

# replace spirit v1.8 with v1.6
	@${RM} -rf ${WRKSRC}/boost/spirit* ${WRKSRC}/libs/spirit
	@${MV} ${WRKDIR}/spirit_${SPIRIT_VERSION:S/./_/g}/boost/* ${WRKSRC}/boost
	@${MV} ${WRKDIR}/spirit_${SPIRIT_VERSION:S/./_/g}/libs/spirit ${WRKSRC}/libs
.endif

post-patch:
# If necessary, remove Boost.Python
.if !defined(WITH_PYTHON)
	@${RM} -rf ${WRKSRC}/boost/python* ${WRKSRC}/libs/python
.endif

# Do the right thing(tm) for pthread support
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|'\
		${WRKSRC}/tools/build/v1/gcc-tools.jam \
		${WRKSRC}/tools/build/v1/gcc-stlport-tools.jam
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|'\
		${WRKSRC}/tools/build/v1/gcc-tools.jam \
		${WRKSRC}/tools/build/v1/gcc-stlport-tools.jam

do-build:
# build the bjam project build tool
	cd ${WRKSRC}/tools/build/jam_src && ./build.sh gcc

# build the library
	@cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_OPTIONS} --prefix=${PREFIX}\
		"-sTOOLS=${BOOST_TOOLS}" "-sBUILD=${BJAM_BUILD}"\
		${BOOST_STL_OPTS}

do-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/do-install

.include <bsd.port.post.mk>
