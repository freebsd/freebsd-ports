# Created by: Trevor Caira <trevor@bitba.se>
# $FreeBSD$
#

PORTNAME=	stripe
PORTVERSION=	1.9.8
PORTREVISION=	2
CATEGORIES=	finance python
MASTER_SITES=	https://code.stripe.com/stripe/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for the Stripe.com payment system

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests1>=0.8.8:${PORTSDIR}/www/py-requests1
TEST_DEPENDS:=	${RUN_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} "s|, '../VERSION'||" ${WRKSRC}/setup.py

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
