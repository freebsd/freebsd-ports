# Created by: gahr

PORTNAME=	catch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.13.6
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Header-only test framework for C++

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++14-lang pathfix python:build
USE_GITHUB=	yes
GH_ACCOUNT=	catchorg
GH_PROJECT=	Catch2

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-test:
	${BUILD_WRKSRC}/projects/SelfTest

.include <bsd.port.mk>
