# Created by: Boris B. Samorodov <bsam@ipt.ru>
# $FreeBSD$

PORTNAME=	Ice
PORTVERSION=	3.5.0
CATEGORIES=	devel python
MASTER_SITES=	http://download.zeroc.com/Ice/3.5/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd@grem.de
COMMENT=	Ice (Internet Communications Engine) language mapping for Python

LICENSE=	GPLv2

BUILD_DEPENDS=	mcpp:${PORTSDIR}/devel/mcpp
LIB_DEPENDS=	Ice.${LIB_VRS}:${PORTSDIR}/devel/ice

USE_GMAKE=	yes
USE_PYTHON=	yes
BUILD_WRKSRC=	${WRKSRC}/py
INSTALL_WRKSRC=	${WRKSRC}/py

LIB_VRS=	${PORTVERSION:S|.||g:C|0$||}
PLIST_SUB=	LIB_VERSION="${PORTVERSION}" LIB_VRS="${LIB_VRS}"
MAKE_ENV=	ICE_HOME="${LOCALBASE}/share/Ice"

# bypass infrastructure bug (taken from www/py-django)
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DEBUG DOCS TESTS
OPTIONS_DEFAULT=TESTS
TESTS_DESC=	Run tests

NO_STAGE=	yes
.include <bsd.port.options.mk>

CFLAGS+=	-ftemplate-depth-128 -fPIC -DPIC -Wall -D_REENTRANT
.if empty(PORT_OPTIONS:MDEBUG)
CFLAGS+=	-DNDEBUG
.endif

.if ${ARCH} == "ia64"
BROKEN=		does not compile on ia64
.endif

.if ((${ARCH} != i386) && (${ARCH} != powerpc))
MAKE_ENV=	LP64=yes
.endif

.if empty(PORT_OPTIONS:MDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 320
PLIST_SUB+=	PYTHON32=""
PLIST_SUB+=	PYTHONPRE32="@comment "
.else
PLIST_SUB+=	PYTHON32="@comment "
PLIST_SUB+=	PYTHONPRE32=""
.endif

PLIST_SUB+=	PYTHON_SUFFIX=${PYTHON_SUFFIX}

post-patch:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g; \
		s|%%DATADIR%%|${DATADIR}|g; \
		s|%%DOCSDIR%%|${DOCSDIR}|g; \
		s|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g' \
		${FILESDIR}/Make.rules.FreeBSD > ${WRKSRC}/cpp/config/Make.rules.FreeBSD
	@${REINPLACE_CMD} 's|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/py/config/Make.rules
	@${REINPLACE_CMD} 's|.(ice_dir).slice|${DATADIR}|g; \
		s|.(prefix).slice|${DATADIR}|g; \
		s|.(prefix).[ICE_]*LICENSE|${DATADIR}/LICENSE|g;' \
		${WRKSRC}/config/Make.common.rules

post-install:
	${ECHO} "Ice" > ${PYTHON_SITELIBDIR}/Ice.pth
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PYTHON_SITELIBDIR}/Ice
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PYTHON_SITELIBDIR}/Ice

.if ${PORT_OPTIONS:MTESTS}
TEST_CMD=	@cd ${BUILD_WRKSRC} && ${PYTHON_CMD} ./allTests.py
.endif

.if ${PORT_OPTIONS:MTESTS}
post-build:
	${TEST_CMD}
regression-test test: build
	${TEST_CMD}
.endif

.include <bsd.port.post.mk>
