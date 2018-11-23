# Created by: Goran Mekić <meka@tilda.center>
# $FreeBSD$

PORTNAME=	dns-lexicon
DISTVERSION=	2.7.14
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Manipulate DNS records on various DNS providers in a standardized way

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tldextract>0:dns/py-tldextract@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
