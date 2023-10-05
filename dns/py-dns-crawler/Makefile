PORTNAME=	dns-crawler
PORTVERSION=	1.5.8
CATEGORIES=	dns python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Crawler for getting info about DNS domains and services
WWW=		https://gitlab.nic.cz/adam/dns-crawler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.4.0:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cert-human>=1.0.7:security/py-cert-human@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=2.1.0,1:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>=0.16.1:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}forcediphttpsadapter>=1.0.1:www/py-forcediphttpsadapter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GeoIP2>=3.0.0:net/py-GeoIP2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hstspreload>=0:www/py-hstspreload@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.10:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>=20.4.0:textproc/py-pyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.9.9:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyicu>=2.6:devel/py-pyicu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=20.0.1,1:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=3.5.3:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.23.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.9.1:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=1.7.0:devel/py-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.25.11,1:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography distutils

NO_ARCH=	yes

.include <bsd.port.mk>
