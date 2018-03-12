# Created by: gahr
# $FreeBSD$

PORTNAME=	catch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.1
CATEGORIES=	devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Header-only test framework for C++

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++14-lang cmake pathfix
USE_GITHUB=	yes
GH_ACCOUNT=	catchorg
GH_PROJECT=	Catch2

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR}
PORTDOCS=	*

do-test:
	${WRKSRC}/SelfTest

.include <bsd.port.mk>
