PORTNAME=	compressed-rtf
DISTVERSION=	1.0.7
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	compressed_rtf-${PORTVERSION}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Compressed RTF compression and decompression package
WWW=		https://github.com/delimitry/compressed_rtf

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
