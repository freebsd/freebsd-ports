# Created by: Trevor Caira <trevor@bitba.se>
# $FreeBSD$
#

PORTNAME=	stripe
PORTVERSION=	1.9.8
PORTREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	https://code.stripe.com/stripe/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trevor@bitba.se
COMMENT=	Python bindings for the Stripe.com payment system

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests1>=0.8.8:${PORTSDIR}/www/py-requests1
TEST_DEPENDS:=	${RUN_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} "s|, '../VERSION'||" ${WRKSRC}/setup.py

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
