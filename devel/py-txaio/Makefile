PORTNAME=	txaio
DISTVERSION=	25.6.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Compatibility API between asyncio/Twisted/Trollius
WWW=		https://github.com/crossbario/txaio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils pytest

NO_ARCH=	yes

OPTIONS_DEFINE=		TWISTED
OPTIONS_DEFAULT=	TWISTED

TWISTED_DESC=	Twisted network backend support

TWISTED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=22.100.0:devel/py-twisted@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zope.interface>=5.2.0:devel/py-zope.interface@${PY_FLAVOR}

.include <bsd.port.mk>
