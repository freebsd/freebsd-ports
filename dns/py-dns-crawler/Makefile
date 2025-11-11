PORTNAME=	dns-crawler
PORTVERSION=	1.6.5
PORTREVISION=	1
CATEGORIES=	dns python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dns_crawler-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Crawler for getting info about DNS domains and services
WWW=		https://gitlab.nic.cz/adam/dns-crawler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=41:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-git-versioning>=0:devel/py-setuptools-git-versioning@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.5.1:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cert-human>=1.0.7:security/py-cert-human@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}checkdmarc>=4.3.1:mail/py-checkdmarc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=2.3.0,1:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>=0.18.0:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}forcediphttpsadapter>=1.0.2:www/py-forcediphttpsadapter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GeoIP2>=3.0.0:net/py-GeoIP2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hstspreload>=0:www/py-hstspreload@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.10:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>=21.10.1:textproc/py-pyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyicu>=2.13.1:devel/py-pyicu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>=23.1.1,1:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>=0.4.27:devel/py-python-magic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=4.5.4:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.23.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.10.1:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq1>=1.13.0:devel/py-rq1@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

.include <bsd.port.mk>
