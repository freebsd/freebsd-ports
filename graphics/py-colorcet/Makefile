PORTNAME=	colorcet
DISTVERSION=	3.0.0
CATEGORIES=	graphics science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Useful perceptually uniform colormaps for plotting scientific data
WWW=		https://colorcet.holoviz.org/

LICENSE=	CC-BY-4.0
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}param>=1.7.0:devel/py-param@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyct>=0.4.4:misc/py-pyct@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest

.include <bsd.port.mk>
