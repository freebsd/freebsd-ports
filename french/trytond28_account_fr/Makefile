# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_account_fr
PORTVERSION=	2.8.0
PORTREVISION=	2
CATEGORIES=	french finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_account_fr/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_account_fr-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (French Account Chart)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_account>=2.8.1:finance/trytond28_account

CONFLICTS=	trytond_account_fr-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
