# Created by: Stefan Ehmann <shoesoft@gmx.net>
# $FreeBSD$

PORTNAME=		Ice
PORTVERSION=		3.5.1
PORTREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://download.zeroc.com/Ice/3.5/

MAINTAINER=		freebsd@grem.de
COMMENT=		Modern alternative to object middleware such as CORBA/COM/DCOM/COM+

LICENSE=		GPLv2

LIB_DEPENDS=		libexpat.so:${PORTSDIR}/textproc/expat2 \
			libmcpp.so:${PORTSDIR}/devel/mcpp

OPTIONS_DEFINE?=	DEBUG DEMOS DOCS TESTS
OPTIONS_DEFAULT?=	DEMOS TESTS
TESTS_DESC?=		Build and run tests (requires lang/python)
DEMOS_DESC?=		Build demos

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
USE_PYTHON_BUILD=	yes
.endif

USES=			iconv gmake
USE_BDB=		yes
WANT_BDB_VER=		5
INVALID_BDB_VER=	40 41 42 43 44 46 47 48 6
USE_LDCONFIG=		yes
BUILD_WRKSRC?=		${WRKSRC}/cpp
INSTALL_WRKSRC?=	${WRKSRC}/cpp

CFLAGS+=		-ftemplate-depth-128 -fPIC -DPIC -Wall -D_REENTRANT -I${LOCALBASE}/include
.if ${PORT_OPTIONS:MDEBUG}
CFLAGS+=		-g
.else
CFLAGS+=		-DNDEBUG
.endif

.if ${ARCH} == "ia64"
BROKEN=			does not compile on ia64
.endif

.if ${ARCH} == "sparc64"
BROKEN=			fails to link
.endif

.if ((${ARCH} != i386) && (${ARCH} != powerpc))
MAKE_ENV+=		LP64=yes
.endif

.if !${PORT_OPTIONS:MTESTS}
MAKE_ENV+=		NOTESTS=yes
.endif

.if !${PORT_OPTIONS:MDEMOS}
MAKE_ENV+=		NODEMOS=yes
.endif

.if !${PORT_OPTIONS:MDOCS}
MAKE_ENV+=		NOICEDOCS=yes
.endif

.include <bsd.port.pre.mk>

.if defined(PYTHON_REL) && ${PYTHON_REL} >= 320
PLIST_SUB+=	PYTHON32=""
PLIST_SUB+=	PYTHONPRE32="@comment "
.else
PLIST_SUB+=	PYTHON32="@comment "
PLIST_SUB+=	PYTHONPRE32=""
.endif

PLIST_SUB+=	PYTHON_SUFFIX=${PYTHON_SUFFIX}

.if ${PREFIX} != ${LOCALBASE} && !defined(NO_STAGE)
PYSITEDIR=	${PREFIX}${PYTHON_SITELIBDIR:S|^${LOCALBASE}||}
.else
PYSITEDIR=	${PYTHON_SITELIBDIR}
.endif

.if ${PORT_OPTIONS:MNAMESPACES}
MAKE_ARGS+=	USE_NAMESPACES=yes
PLIST_SUB+=	NAMESPACES=""
PLIST_SUB+=	NONAMESPACES="@comment "
.else
PLIST_SUB+=	NAMESPACES="@comment "
PLIST_SUB+=	NONAMESPACES=""
.endif

post-patch:
	@${SED} 's|%%PREFIX%%|${STAGEDIR}${PREFIX}|g; \
		s|%%DATADIR%%|${STAGEDIR}${DATADIR}|g; \
		s|%%DOCSDIR%%|${STAGEDIR}${DOCSDIR}|g; \
		s|%%ICONV_LIB%%|${ICONV_LIB}|g; \
		s|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g' \
		${FILESDIR}/Make.rules.FreeBSD > ${WRKSRC}/cpp/config/Make.rules.FreeBSD
	@${REINPLACE_CMD} 's|%%BDB_LIB_CXX_NAME%%|${BDB_LIB_CXX_NAME}|g; \
		s|%%BDB_LIB_DIR%%|${BDB_LIB_DIR}|g; \
		s|%%BDB_INCLUDE_DIR%%|${BDB_INCLUDE_DIR}|g; \
		/install_docdir/d' \
		${WRKSRC}/cpp/config/Make.rules
	@${REINPLACE_CMD} '/install_configdir/d' \
		${WRKSRC}/cpp/config/Make.rules
	@${REINPLACE_CMD} 's|INSTALL_PROGRAM|INSTALL_DATA|g' \
		${WRKSRC}/cpp/src/ca/Makefile
	@${REINPLACE_CMD} '/LICENSE/s/prefix/install_slicedir/; \
		s|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; ' \
		${WRKSRC}/config/Make.common.rules
	@${REINPLACE_CMD} 's|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%ICONV_LIB%%|${ICONV_LIB}|g; \
		s|%%PYTHON_SITELIBDIR%%|${STAGEDIR}${PYSITEDIR}|g; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/py/config/Make.rules
	@${REINPLACE_CMD} 's|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/php/config/Make.rules.php

.if ${PORT_OPTIONS:MTESTS}
TEST_CMD=		@cd ${BUILD_WRKSRC} && ${PYTHON_CMD} ./allTests.py
post-build:
	${TEST_CMD}
regression-test test: build
	${TEST_CMD}
.endif

.include <bsd.port.post.mk>
