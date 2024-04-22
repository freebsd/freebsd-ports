PORTNAME=	mac-vendor-lookup
DISTVERSION=	0.1.12
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mac_vendor_lookup-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Find the vendor for a given MAC address
WWW=		https://github.com/bauerj/mac_vendor_lookup

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}aiohttp>=2.3.5:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiofiles>=0:devel/py-aiofiles@${PY_FLAVOR}

USES=		dos2unix python
DOS2UNIX_FILES=	${WRKSRC}/setup.py
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
