PORTNAME=	prodigy-lig
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	biology python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Prediction of protein-small molecule binding affinities
WWW=		https://nestor.science.uu.nl/prodigy/lig

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR}

USES=		gmake python
USE_PYTHON=	distutils noflavors autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	haddocking

NO_ARCH=	yes

.include <bsd.port.mk>
