PORTNAME=	catch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.13.9
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Header-only test framework for C++
WWW=		https://github.com/catchorg/Catch2

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++14-lang pathfix python:build
USE_GITHUB=	yes
GH_ACCOUNT=	catchorg
GH_PROJECT=	Catch2

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR}
PORTDOCS=	*

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	limit:2.*

do-test:
	${BUILD_WRKSRC}/projects/SelfTest

.include <bsd.port.mk>
