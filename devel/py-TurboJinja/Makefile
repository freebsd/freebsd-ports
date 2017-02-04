# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	TurboJinja
PORTVERSION=	0.9.1
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Jinja (Django & Smarty-like) template for TurboGears

DEPRECATED=	Development of this branch ceased
EXPIRATION_DATE=	2017-03-03

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}TurboGears>=1.1.2:www/py-turbogears
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Jinja>=0.9:devel/py-Jinja

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
