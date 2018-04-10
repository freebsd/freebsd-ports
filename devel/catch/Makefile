# Created by: gahr
# $FreeBSD$

PORTNAME=	catch
DISTVERSION=	2.2.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/catchorg/Catch2/archive/
DISTNAME=	v${DISTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Header-only test framework for C++

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++14-lang cmake pathfix
WRKSRC=		${WRKDIR}/Catch2-${DISTVERSION}

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR}
PORTDOCS=	*

do-test:
	${WRKSRC}/SelfTest

.include <bsd.port.mk>
