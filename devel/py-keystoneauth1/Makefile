PORTNAME=	keystoneauth1
PORTVERSION=	5.11.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Authentication Library for OpenStack Identity
WWW=		https://docs.openstack.org/keystoneauth/latest/ \
		https://github.com/openstack/keystoneauth

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.14.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.20.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}os-service-types>=1.2.0:devel/py-os-service-types@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	BETAMAX KERBEROS OAUTH1 SAML2
BETAMAX_DESC=	Betamax support
OAUTH1_DESC=	OAuth 1.0 support
SAML2_DESC=	SAML 2.0 support

BETAMAX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}betamax>=0.7.0:www/py-betamax@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}fixtures>=3.0.0:devel/py-fixtures@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyyaml>=3.13:devel/py-pyyaml@${PY_FLAVOR}
KERBEROS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests-kerberos>=0.8.0:security/py-requests-kerberos@${PY_FLAVOR}
OAUTH1_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oauthlib>=0.6.2:security/py-oauthlib@${PY_FLAVOR}
SAML2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=4.2.0:devel/py-lxml@${PY_FLAVOR}

.include <bsd.port.mk>
