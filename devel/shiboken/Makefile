# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shiboken
PORTVERSION=	1.2.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://download.qt-project.org/official_releases/pyside/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ code generator for CPython extensions

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libxslt.so:textproc/libxslt

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		PYTHON_VERSION=${PYTHON_VERSION}

USE_QT=		corelib qmake_build qtestlib moc_build network \
		uic_build rcc_build xml xmlpatterns

USES=		cmake:insource python:2.7 qt:4 tar:bzip2
USE_LDCONFIG=	yes

ALL_TARGET=	all
TEST_TARGET=	test

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

MANPAGES_PLIST_FILES=	man/man1/shiboken.1.gz
MANPAGES_CMAKE_OFF=	-DNO_INSTALL_MANPAGES:BOOL="ON"

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_ALL_TARGET=	doc

post-install-DOCS-on:
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-patch:
	@cd ${WRKSRC}/generator && \
		${MV} ${PORTNAME} ${PORTNAME}.dir

.include <bsd.port.mk>
