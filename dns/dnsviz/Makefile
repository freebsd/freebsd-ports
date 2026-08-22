PORTNAME=	dnsviz
PORTVERSION=	0.11.1
DISTVERSIONPREFIX=v
CATEGORIES=	dns

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Analysis and visualization of DNS/DNSSEC behavior
WWW=		https://dnsviz.net/

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>=1.6:graphics/py-pygraphviz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=48.0.1:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=2.8.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libnacl>=2.1.0:security/py-libnacl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils concurrent optsuffix
USE_GITHUB=	yes
PYDISTUTILS_INSTALLNOSINGLE=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
