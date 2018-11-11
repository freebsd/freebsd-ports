# $FreeBSD$

PORTNAME=	unittest2
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	New features in unittest backported to Python 2

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traceback2>=0:devel/py-traceback2@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traceback2>=0:devel/py-traceback2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|'argparse', ||" ${WRKSRC}/setup.py

.include <bsd.port.mk>
