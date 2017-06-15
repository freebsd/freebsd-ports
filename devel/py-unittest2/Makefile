# $FreeBSD$

PORTNAME=	unittest2
PORTVERSION=	1.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	New features in unittest backported to Python 2

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}linecache2>0:devel/py-linecache2 \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}traceback2>0:devel/py-traceback2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}linecache2>0:devel/py-linecache2 \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}traceback2>0:devel/py-traceback2

USES=		python
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e "s|'argparse', ||" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
