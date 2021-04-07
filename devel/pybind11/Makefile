PORTNAME=	pybind11
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.2
CATEGORIES=	devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Seamless interoperability between C++11 and Python (cmake part)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang python:build

USE_GITHUB=	yes
GH_ACCOUNT=	pybind

CMAKE_OFF=	PYBIND11_TEST

NO_ARCH=	yes

.include <bsd.port.mk>
