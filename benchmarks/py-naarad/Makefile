# $FreeBSD$

PORTNAME=	naarad
PORTVERSION=	1.0.15
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Framework for performance analysis

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>0:devel/py-argparse \
	${PYTHON_PKGNAMEPREFIX}pytz>=2013.8:devel/py-pytz \
	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2 \
	${PYTHON_PKGNAMEPREFIX}luminol>0:math/py-luminol \
	bash:shells/bash \
	gawk:lang/gawk

USES=		shebangfix python

SHEBANG_LANG=	gawk
SHEBANG_FILES=	bin/naarad_metric_collector.sh bin/PrintGCStats

USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes
GH_ACCOUNT=	linkedin

.include <bsd.port.mk>
