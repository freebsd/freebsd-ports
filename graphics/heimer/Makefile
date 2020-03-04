# $FreeBSD$

PORTNAME=	heimer
DISTVERSION=	1.15.1
CATEGORIES=	graphics

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Simple mind map, diagram, and note-taking tool

LICENSE=	CC-BY-SA-3.0 GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	juzzlin
GH_PROJECT=	Heimer
USE_QT=		core gui widgets xml buildtools_build linguisttools_build \
		qmake_build testlib_build
TEST_TARGET=	test

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/heimer

post-install-EXAMPLES-on:
	cd ${WRKSRC}/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
