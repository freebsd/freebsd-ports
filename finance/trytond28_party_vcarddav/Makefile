# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_party_vcarddav
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_party_vcarddav/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_party_vcarddav-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Party VCardDAV Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_party>=2.8.0:finance/trytond28_party \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.8.1:deskutils/py-vobject@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyWebDAV>=0:www/py-pywebdav@${FLAVOR}

CONFLICTS=	trytond_party_vcarddav-2.[46].*

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
