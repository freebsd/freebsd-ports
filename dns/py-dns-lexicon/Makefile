PORTNAME=	dns-lexicon
PORTVERSION=	3.21.1
CATEGORIES=	dns python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dns_lexicon-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate DNS records on various DNS providers in a standardized way
WWW=		https://github.com/AnalogJ/lexicon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=2,1:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyotp>=2:security/py-pyotp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tldextract>=2:dns/py-tldextract@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	GRANSY LOCALZONE OCI ROUTE53 SOFTLAYER
GRANSY_DESC=	Gransy support
LOCALZONE_DESC=	localzone support
OCI_DESC=	Oracle Cloud Infrastructure (OCI) support
ROUTE53_DESC=	Route 53 support
SOFTLAYER_DESC=	SoftLayer (IBM Cloud) support

GRANSY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zeep>=3:net/py-zeep@${PY_FLAVOR}
LOCALZONE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}localzone>=0.9.8:dns/py-localzone@${PY_FLAVOR}
OCI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oci>=2:devel/py-oci@${PY_FLAVOR}
ROUTE53_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.28:www/py-boto3@${PY_FLAVOR}
SOFTLAYER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}softlayer>=5:net/py-softlayer@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.6:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
