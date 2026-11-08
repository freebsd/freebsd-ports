PORTNAME=	grammalecte-fr
PORTVERSION=	2.3.0
CATEGORIES=	french python
MASTER_SITES=	https://www.grammalecte.net/zip/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Grammalecte-fr-v${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	French grammar and typographic corrector
WWW=		https://grammalecte.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
USES=		python zip
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes
WRKSRC=		${WRKDIR}

.include <bsd.port.mk>
