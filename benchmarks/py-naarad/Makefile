PORTNAME=	naarad
PORTVERSION=	1.0.15
PORTREVISION=	7
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for performance analysis
WWW=		https://github.com/LinkedInAttic/naarad

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Upstream last activity was in 2016, and the project has been moved to the LinkedInAttic GitHub account.
EXPIRATION_DATE=	2026-07-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>=2013.8,1:devel/py-pytz@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}luminol>0:math/py-luminol@${PY_FLAVOR} \
	bash:shells/bash \
	gawk:lang/gawk

USES=		shebangfix python

SHEBANG_LANG=	gawk
SHEBANG_FILES=	bin/naarad_metric_collector.sh bin/PrintGCStats

USE_PYTHON=	autoplist concurrent distutils
USE_GITHUB=	yes
GH_ACCOUNT=	linkedin

NO_ARCH=	yes

.include <bsd.port.mk>
