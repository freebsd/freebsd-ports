# Created by: Trevor Caira <trevor@bitba.se>
# $FreeBSD$
#

PORTNAME=	stripe
PORTVERSION=	1.9.5
CATEGORIES=	finance python
MASTER_SITES=	https://code.stripe.com/stripe/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trevor@bitba.se
COMMENT=	Python bindings for the Stripe.com payment system

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0.8.8:${PORTSDIR}/www/py-requests
TEST_DEPENDS:=	${RUN_DEPENDS

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} 's/version=version\.VERSION,/version=version.VERSION, zip_safe=False,/' \
		${WRKSRC}/setup.py

NO_STAGE=	yes

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
