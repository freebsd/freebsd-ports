PORTNAME=	ioflo
PORTVERSION=	2.0.0
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Automated Reasoning Engine and Flow Based Programming Framework
WWW=		https://ioflo.com

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-2.0.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git>=1.1:devel/py-setuptools-git@${PY_FLAVOR}

USES=		python shebangfix

USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

SHEBANG_FILES=	scripts/ioflo

.include <bsd.port.mk>
