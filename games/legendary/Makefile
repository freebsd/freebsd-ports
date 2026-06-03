PORTNAME=	legendary
DISTVERSION=	1.12.0
CATEGORIES=	games

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Free and open-source replacement for the Epic Games Launcher
WWW=		https://github.com/RareDevs/legendary

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>=0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-futures>=0:www/py-requests-futures@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	RareDevs
GH_TAGNAME=	rare-${DISTVERSION}

USE_PYTHON=	autoplist noflavors distutils

NO_ARCH=	yes

.include <bsd.port.mk>
