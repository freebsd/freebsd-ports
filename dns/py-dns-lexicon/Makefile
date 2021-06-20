# Created by: Goran Mekić <meka@tilda.center>

PORTNAME=	dns-lexicon
PORTVERSION=	3.6.0
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate DNS records on various DNS providers in a standardized way

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4<5:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2<4:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3<6:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tldextract>=2<4:dns/py-tldextract@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	DDNS GRANSY LOCALZONE ROUTE53 SOFTLAYER TRANSIP
DDNS_DESC=	Dynamic DNS support
GRANSY_DESC=	Gransy support
LOCALZONE_DESC=	localzone support
ROUTE53_DESC=	Route 53 support
SOFTLAYER_DESC=	SoftLayer (IBM Cloud) support
TRANSIP_DESC=	TransIP support

DDNS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython2>=2<3:dns/py-dnspython2@${PY_FLAVOR}
GRANSY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zeep>=3<5:net/py-zeep@${PY_FLAVOR}
LOCALZONE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}localzone>=0.9.8<1:dns/py-localzone@${PY_FLAVOR}
ROUTE53_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1<2:www/py-boto3@${PY_FLAVOR}
SOFTLAYER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}softlayer>=5<6:net/py-softlayer@${PY_FLAVOR}
TRANSIP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}transip>=2<3:net/py-transip@${PY_FLAVOR}

.include <bsd.port.mk>
