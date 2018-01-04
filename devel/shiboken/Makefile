# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shiboken
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://download.qt-project.org/official_releases/pyside/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	C++ code generator for CPython extensions

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libxslt.so:textproc/libxslt

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		PYTHON_VERSION=${PYTHON_VERSION}

USE_QT4=	corelib qmake_build qtestlib moc_build network \
		uic_build rcc_build xml xmlpatterns

USES=		cmake python:2.7 tar:bzip2
USE_LDCONFIG=	yes

ALL_TARGET=	all

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES}
PLIST_FILES+=	man/man1/shiboken.1.gz
.else
CMAKE_ARGS=	-DNO_INSTALL_MANPAGES:BOOL="ON"
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:textproc/py-sphinx
ALL_TARGET+=	doc
post-install:
	if [ -d ${WRKSRC}/doc/html ]; then \
		${MKDIR} ${STAGEDIR}${DOCSDIR} && \
		cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}; \
	fi
.endif

post-patch:
	@cd ${WRKSRC}/generator && \
	${MV} ${PORTNAME} ${PORTNAME}.dir

regression-test: build
	@${ECHO_MSG} "===> Running shiboken regression tests"
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
