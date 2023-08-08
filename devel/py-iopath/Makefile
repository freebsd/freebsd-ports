PORTNAME=	iopath
PORTVERSION=	0.1.9
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Library providing I/O interface among storage backends
WWW=		https://github.com/facebookresearch/iopath

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}portalocker>0:devel/py-portalocker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	facebookresearch
GH_TAGNAME=	b49ef53b557b794ad142047905827a6727b91d63
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
