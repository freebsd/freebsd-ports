# New ports collection makefile for:	hypertable
# Date created:	   20 Aug 2010
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	hypertable
DISTVERSION=	0.9.3.4-alpha
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	skv@FreeBSD.org
COMMENT=	High performance distributed data storage system

RUN_DEPENDS=	bash>=3.0:${PORTSDIR}/shells/bash
LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2 \
		thrift.0:${PORTSDIR}/devel/thrift \
		event:${PORTSDIR}/devel/libevent \
		log4cpp:${PORTSDIR}/devel/log4cpp \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		rrd:${PORTSDIR}/databases/rrdtool \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl \
		sigar:${PORTSDIR}/sysutils/hyperic-sigar
BUILD_DEPENDS=	${RUN_DEPENDS} \
		ant:${PORTSDIR}/devel/apache-ant

BROKEN=		does not build

OPTIONS=	TCMALLOC	"Use Tcmalloc"			on  \
		HOARD		"Use Hoard"			off \
		PYTHONLIBS	"Add Python binding"		off \
		THRIFT_PERL	"Thrift binding for Perl"	off \
		THRIFT_PYTHON	"Thrift binding for Python"	off \
		THRIFT_RUBY	"Thrift binding for Ruby"	off

USE_BDB=	yes
WANT_BDB_VER=	48

USE_CMAKE=	yes
CMAKE_BUILD_TYPE=	RelWithDebinfo
CMAKE_INSTALL_PREFIX=	${PREFIX}/hypertable
CMAKE_SOURCE_PATH=	${WRKDIR}/${PORTNAME}-${DISTVERSION}
CMAKE_ARGS+=	-DINSTALL_EXCLUDE_DEPENDENT_LIBS=1

PATCH_WRKSRC=	${CMAKE_SOURCE_PATH}

WRKSRC=		${WRKDIR}/build

USE_GMAKE=	yes

USE_LDCONFIG=	${PREFIX}/hypertable/lib

DONT_DETECT=	Doxygen Kfs Ceph Ant JNI PHP5Thrift

.include <bsd.port.options.mk>

.if defined(WITH_TCMALLOC)
LIB_DEPENDS+=	tcmalloc.1:${PORTSDIR}/devel/google-perftools
PLIST_SUB+=	TCMALLOC=""
.else
DONT_DETECT+=	Tcmalloc
PLIST_SUB+=	TCMALLOC="@comment "
.endif

.if defined(WITH_HOARD)
LIB_DEPENDS+=	hoard.so.1:${PORTSDIR}/devel/libhoard
PLIST_SUB+=	HOARD=""
.else
DONT_DETECT+=	Hoard
PLIST_SUB+=	HOARD="@comment "
.endif

.if defined(WITH_PYTHONLIBS)
USE_PYTHON=	yes
LIB_DEPENDS+=	boost_python:${PORTSDIR}/devel/boost-python-libs
.else
DONT_DETECT+=	PythonLibs
.endif

.if defined(WITH_THRIFT_PERL)
BUILD_DEPENDS+=	p5-Thrift>=0:${PORTSDIR}/devel/p5-Thrift
.else
DONT_DETECT+=	PerlThrift
.endif

.if defined(WITH_THRIFT_PYTHON)
USE_PYTHON=	yes
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}thrift>=0:${PORTSDIR}/devel/py-thrift
.else
DONT_DETECT+=	PythonThrift
.endif

.if defined(WITH_THRIFT_RUBY)
BUILD_DEPENDS+=	ruby-thrift>=0:${PORTSDIR}/devel/ruby-thrift
.else
DONT_DETECT+=	RubyThrift
.endif

pre-everything::
.if defined(WITH_THRIFT_PERL) && !defined(WITH_THRIFT)
	@${ECHO_CMD} "please enable THRIFT option to use THRIFT_PERL"
	@${FALSE}
.endif
.if defined(WITH_THRIFT_PYTHON) && !defined(WITH_THRIFT)
	@${ECHO_CMD} "please enable THRIFT option to use THRIFT_PYTHON"
	@${FALSE}
.endif
.if defined(WITH_THRIFT_RUBY) && !defined(WITH_THRIFT)
	@${ECHO_CMD} "please enable THRIFT option to use THRIFT_RUBY"
	@${FALSE}
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -i '' -e 's=/opt/local=${LOCALBASE}=' \
		${PATCH_WRKSRC}/cmake/*.cmake
	@${REINPLACE_CMD} -i '' -e 's=/usr/local/BerkeleyDB.4.8/include=${BDB_INCLUDE_DIR}=; \
		s=/usr/local/BerkeleyDB.4.8/lib=${BDB_LIB_DIR}=' \
		${PATCH_WRKSRC}/cmake/FindBerkeleyDB.cmake
	@${REINPLACE_CMD} -i '' -E '/^set\(CMAKE_INSTALL_PREFIX/d' \
		${PATCH_WRKSRC}/CMakeLists.txt
	@${FIND} ${PATCH_WRKSRC} -name "*.orig" -delete

pre-configure:
	@${MKDIR} ${WRKSRC}
.for _D in ${DONT_DETECT}
	@${REINPLACE_CMD} -i '' -E '/^find_package\(${_D}\)/d' \
		${PATCH_WRKSRC}/CMakeLists.txt
.endfor

test: build
	(cd ${WRKSRC} && ${GMAKE} alltests)

.include <bsd.port.post.mk>
