PORTNAME=	electrum-aionostr
DISTVERSION=	0.0.11
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Asyncio nostr client
WWW=		https://pypi.org/project/electrum-aionostr/ \
		https://github.com/spesmilo/electrum-aionostr

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp-socks>=0.9.2:net/py-aiohttp-socks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.11.0,<4.0.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiorpcX>=0.22.0:devel/py-aiorpcX@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}electrum-ecc>0:devel/py-electrum-ecc@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

post-extract:
	@${RM} ${WRKSRC}/setup.py

.include <bsd.port.mk>
