# Created by: Goran Mekić <meka@tilda.center>
# $FreeBSD$

PORTNAME=	dns-lexicon
PORTVERSION=	2.0.7
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Manipulate DNS records on various DNS providers in a standardized way

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0.16:devel/py-future \
		${PYTHON_PKGNAMEPREFIX}tldextract>=1.7.5:dns/py-tldextract \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11:www/py-requests

USES=		python
USE_PYTHON=	distutils autoplist
NO_ACRH=	yes

.include <bsd.port.mk>
