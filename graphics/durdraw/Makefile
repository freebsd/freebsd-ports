PORTNAME=	durdraw
DISTVERSION=	0.29.0
CATEGORIES=	graphics python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ASCII and ANSI Art text editor for drawing in the terminal
WWW=		https://durdraw.org/ \
		https://github.com/cmang/durdraw

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_PILLOW}

USES=		python
USE_PYTHON=	pep517 noflavors autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	cmang

NO_ARCH=	yes

.include <bsd.port.mk>
