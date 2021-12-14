PORTNAME=	peak-classifier
DISTVERSION=	0.1.2
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Classify ChIP/ATAC-Seq peaks based on features provided in a GFF

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxtend.so:devel/libxtend libbiolibc.so:biology/biolibc
RUN_DEPENDS=	bedtools:biology/bedtools \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

USES=		localbase python:3.7+ shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	auerlab
SHEBANG_FILES=	feature-view.py

pre-build:
	cd ${WRKSRC} && make depend LOCALBASE=${LOCALBASE}

.include <bsd.port.mk>
