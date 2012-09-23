# Created by: Stefan Ehmann <shoesoft@gmx.net>
# $FreeBSD$

PORTNAME=		Ice
PORTVERSION=		3.4.2
PORTREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		http://download.zeroc.com/Ice/3.4/

MAINTAINER=		freebsd@grem.de
COMMENT=		Modern alternative to object middleware such as CORBA/COM/DCOM/COM+

LIB_DEPENDS=		expat:${PORTSDIR}/textproc/expat2 \
			mcpp:${PORTSDIR}/devel/mcpp

OPTIONS_DEFINE=		DEBUG DEMOS DOCS TESTS
OPTIONS_DEFAULT=	DEMOS TESTS
TESTS_DESC=		Build and run tests (requires lang/python)
DEMOS_DESC=		Build demos

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
USE_PYTHON_BUILD=	yes
.endif

USE_GMAKE=		yes
USE_ICONV=		yes
USE_BDB=		42+
INVALID_BDB_VER=	2 3 40 41
USE_LDCONFIG=		yes
BUILD_WRKSRC=		${WRKSRC}/cpp
INSTALL_WRKSRC=		${WRKSRC}/cpp

CFLAGS+=		-ftemplate-depth-128 -fPIC -DPIC -Wall -D_REENTRANT ${PTHREAD_CFLAGS} -I${LOCALBASE}/include
.if !${PORT_OPTIONS:MDEBUG}
CFLAGS+=		-DNDEBUG
.endif

.if ${ARCH} == "ia64"
BROKEN=			does not compile on ia64
.endif

.if ${ARCH} == "sparc64"
BROKEN=			fails to link
.endif

.if ((${ARCH} != i386) && (${ARCH} != powerpc))
MAKE_ENV=		LP64=yes
.endif

.if !${PORT_OPTIONS:MTESTS}
MAKE_ENV+=		NOTESTS=yes
.endif

.if !${PORT_OPTIONS:MDEMOS}
MAKE_ENV+=		NODEMOS=yes
.endif

.if !${PORT_OPTIONS:MDOCS}
MAKE_ENV+=		NOPORTDOCS=yes
.endif

post-patch:
	@${SED} 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g; \
		s|%%PREFIX%%|${PREFIX}|g; \
		s|%%DATADIR%%|${DATADIR}|g; \
		s|%%DOCSDIR%%|${DOCSDIR}|g; \
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
	@${REINPLACE_CMD} '/LICENSE/s/prefix/install_slicedir/' \
		${WRKSRC}/config/Make.common.rules

.if ${PORT_OPTIONS:MTESTS}
TEST_CMD=		@cd ${BUILD_WRKSRC} && ${PYTHON_CMD} ./allTests.py
post-build:
	${TEST_CMD}
regression-test test: build
	${TEST_CMD}
.endif

.include <bsd.port.mk>
