# $FreeBSD$

PORTNAME=	prodigy-lig
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-3
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g152ac59
CATEGORIES=	biology python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Prediction of protein-small molecule binding affinities

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR}

USES=		gmake python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	haddocking
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
