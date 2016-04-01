# $FreeBSD$

PORTNAME=	unittest2
PORTVERSION=	0.8.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	New features in unittest backported to Python 2.4+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e "s|'argparse', 'six'|'six'|" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
