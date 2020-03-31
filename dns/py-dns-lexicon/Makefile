# Created by: Goran Mekić <meka@tilda.center>
# $FreeBSD$

PORTNAME=	dns-lexicon
PORTVERSION=	3.3.19
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Manipulate DNS records on various DNS providers in a standardized way

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tldextract>=0:dns/py-tldextract@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	EASYNAME GRANSY GRATISDNS HENET HETZNER LOCALZONE NAMECHEAP PLESK ROUTE53 SOFTLAYER SUBREG TRANSIP
EASYNAME_DESC=	easyname support
GRANSY_DESC=	Gransy support
GRATISDNS_DESC=	GratisDNS support
HENET_DESC=	Hurricane Electric support
HETZNER_DESC=	Hetzner support
LOCALZONE_DESC=	localzone support
NAMECHEAP_DESC=	Namecheap support
PLESK_DESC=	Plesk support
ROUTE53_DESC=	Route 53 support
SOFTLAYER_DESC=	SoftLayer (IBM Cloud) support
SUBREG_DESC=	Subreg support
TRANSIP_DESC=	TransIP support

EASYNAME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR}
GRANSY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zeep>=0:net/py-zeep@${PY_FLAVOR}
GRATISDNS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR}
HENET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR}
HETZNER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}dnspython>=1.15.0:dns/py-dnspython@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}html5lib>=0:www/py-html5lib@${PY_FLAVOR}
LOCALZONE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}localzone>=0:dns/py-localzone@${PY_FLAVOR}
NAMECHEAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pynamecheap>=0:net/py-pynamecheap@${PY_FLAVOR}
PLESK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xmltodict>=0:devel/py-xmltodict@${PY_FLAVOR}
ROUTE53_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=0:www/py-boto3@${PY_FLAVOR}
SOFTLAYER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}softlayer>=0:net/py-softlayer@${PY_FLAVOR}
SUBREG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zeep>=0:net/py-zeep@${PY_FLAVOR}
TRANSIP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}transip>=0.3.0:net/py-transip@${PY_FLAVOR}

.include <bsd.port.mk>
