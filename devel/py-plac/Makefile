PORTNAME=	plac
DISTVERSION=	1.4.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line arguments parser for python
WWW=		https://github.com/ialbert/plac

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>0:devel/py-argparse@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
