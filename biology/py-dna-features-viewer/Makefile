PORTNAME=	dna-features-viewer
DISTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dna_features_viewer-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python library to visualize DNA features, e.g. GenBank or Gff files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcbio-gff>0:biology/py-bcbio-gff@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
