PORTNAME=	stringzilla
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.1
CATEGORIES=	devel python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SIMD-accelerated string search/sort/hashes/fingerprints/edit distances
WWW=		https://ashvardanian.com/posts/stringzilla/ \
		https://github.com/ashvardanian/stringzilla

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	ashvardanian
GH_PROJECT=	StringZilla

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/stringzilla${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
