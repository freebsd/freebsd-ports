# ex:ts=8
# Ports collection makefile for:  boost
# Date Created:			  6 January 2002
# Whom:				  Paul Marquis <pmarquis@pobox.com>
#
# $FreeBSD$
#
# This port has the following tunable options:
#
# option                | desscription                | default
# ----------------------+-----------------------------+---------
# WITH_PYTHON           | enable Python support       | off
# WITH_DEBUG            | build debugging symbols     | off
# WITHOUT_THREADS       | turn off threading support  | off
# WITH_OPTIMIZED_CFLAGS | enable -O3 optimization     | off
#                       | (otherwise CFLAGS are       |
#                       |  respected)                 |
# VERBOSE_BUILD         | show compiler messages      | off

PORTNAME=	boost
PORTVERSION=	1.31.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	barner@gmx.de
COMMENT=	Free peer-reviewed portable C++ source libraries

USE_BZIP2=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

MAKE_ENV+=	GCC="${CC} ${CFLAGS}"\
		GXX="${CXX} ${CXXFLAGS}"

.if defined(WITH_PYTHON)
USE_PYTHON=	2.3+
PYTHON_VERSION=	python2.3
PLIST_SUB=	BOOST_PYTHON=""
MAKE_ENV+=	PYTHON_ROOT="${PREFIX}"\
		PYTHON_VERSION="${PYTHON_VERSION}"\
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}"\
		PYTHON_LIB_PATH="${PYTHON_LIBDIR}"
.else
PLIST_SUB=	BOOST_PYTHON="@comment "
.endif

.include <bsd.port.pre.mk>

.if defined (VERBOSE_BUILD)
BJAM_OPTIONS=	-d2
.endif

.if defined (WITH_DEBUG)
BJAM_BUILD=	debug
.else
BJAM_BUILD=	release
.endif

.if defined (WITHOUT_THREADS)
BJAM_BUILD+=	<threading>single
PLIST_SUB+=	BOOST_THREADS="@comment "
.else
BJAM_BUILD+=	<threading>multi
PLIST_SUB+=	BOOST_THREADS=""
.endif

.if defined (WITH_OPTIMIZED_CFLAGS)
BJAM_BUILD+=	<optimization>speed\
		<inlining>full
.else
BJAM_BUILD+=	<optimization>off
.endif

.if ${ARCH} == alpha
BJAM=		${WRKSRC}/tools/build/jam_src/bin.freebsdaxp/bjam
# temporary work around for GCC bug on alpha
# ("-mcpu=ev4 -mtune=ev5 -mieee" makes gcc consume all virtual memory)
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
		TAR="${TAR}"

.if !defined(NOPORTDOCS)
SCRIPTS_ENV+=	PORTDOCS="true"\
		DOCSDIR="${DOCSDIR}"\
		EXAMPLESDIR="${EXAMPLESDIR}"
.endif

# Do the right thing(tm) for pthread support
post-patch:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|'\
		${WRKSRC}/tools/build/v1/gcc-tools.jam
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|'\
		${WRKSRC}/tools/build/v1/gcc-tools.jam

do-build:
# Print configuration
	@${ECHO_CMD}
	@${ECHO_CMD} Selected options:
	@${ECHO_CMD} \(see the Makefile for a description of available tunables\)
	@${ECHO_CMD}
	@${ECHO_CMD} -n o Debugging symbols....
.if defined (WITH_DEBUG)
	@${ECHO_CMD} yes
.else
	@${ECHO_CMD} no
.endif

	@${ECHO_CMD} -n o Thread support.......
.if defined (WITHOUT_THREADS)
	@${ECHO_CMD} no
.else
	@${ECHO_CMD} yes
.endif

	@${ECHO_CMD} -n o Extra optimization...
.if defined (WITH_OPTIMIZED_CFLAGS)
	@${ECHO_CMD} yes
.else
	@${ECHO_CMD} no
.endif

	@${ECHO_CMD} -n o Python support.......
.if defined (WITH_PYTHON)
	@${ECHO_CMD} yes
.else
	@${RM} -rf ${WRKSRC}/libs/python
	@${ECHO_CMD} no
.endif
	@${ECHO_CMD}

# build the bjam project build tool
	@cd ${WRKSRC}/tools/build/jam_src && ./build.sh gcc

# build the library
	@cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_OPTIONS} --prefix=${PREFIX}\
		"-sTOOLS=gcc" "-sBUILD=${BJAM_BUILD}"

do-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/do-install

.include <bsd.port.post.mk>
