PORTNAME=	fasda-utils
DISTVERSION=	0.1.0-2
DISTVERSIONSUFFIX=	-gf9217f0
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast and simple differential analysis extras
WWW=		https://github.com/auerlab/fasda-utils

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}seaborn>=0:math/py-seaborn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastcluster>=0:math/py-fastcluster@${PY_FLAVOR}

USES=		python:run shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	Scripts/heatmap.py

GH_ACCOUNT=	auerlab

MAKE_ARGS=	MANPREFIX=${PREFIX}/share VERSION=${PORTVERSION}

PLIST_FILES=	libexec/fasda/heatmap \
		libexec/fasda/heatmap.py \
		share/man/man1/fasda-heatmap.1.gz

.include <bsd.port.mk>
