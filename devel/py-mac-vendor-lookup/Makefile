PORTNAME=	mac-vendor-lookup
PORTVERSION=	0.1.11
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Find the vendor for a given MAC address

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}aiohttp>=2.3.5:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiofiles>=0:devel/py-aiofiles@${PY_FLAVOR}

USES=		dos2unix python:3.7+
DOS2UNIX_FILES=	${WRKSRC}/setup.py
USE_PYTHON=	autoplist concurrent distutils

USE_GITHUB=	yes
GH_ACCOUNT=	bauerj
GH_PROJECT=	mac_vendor_lookup

.include <bsd.port.mk>
