PORTNAME=	pure-sasl
DISTVERSION=	0.6.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Pure Python client SASL implementation
WWW=		https://github.com/thobbs/pure-sasl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517
NO_ARCH=	yes

OPTIONS_DEFINE=		GSSAPI
OPTIONS_DEFAULT=	GSSAPI

GSSAPI_DESC=		GSSAPI/Kerberos mechanism support
GSSAPI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}kerberos>=1.3.0:security/py-kerberos@${PY_FLAVOR}

.include <bsd.port.mk>
