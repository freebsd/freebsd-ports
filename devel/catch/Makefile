# Created by: gahr
# $FreeBSD$

PORTNAME=	catch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Header-only test framework for C++

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_powerpc64=	fails to compile: catch_tostring.cpp:206:21: comparison is always true due to limited range of data type

USES=		compiler:c++14-lang cmake:outsource pathfix
USE_GITHUB=	yes
GH_ACCOUNT=	catchorg
GH_PROJECT=	Catch2

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR}
PORTDOCS=	*

do-test:
	${BUILD_WRKSRC}/projects/SelfTest

.include <bsd.port.mk>
