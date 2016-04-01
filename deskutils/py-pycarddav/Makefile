# Created by: che@bein.link
# $FreeBSD$

PORTNAME=	pyCardDAV
PORTVERSION=	0.7.0
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	che@bein.link
COMMENT=	CardDAV based address book tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=3.2:devel/py-click \
		${PYTHON_PKGNAMEPREFIX}urwid>=1.2.1:devel/py-urwid \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.4.1:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.8.0:deskutils/py-vobject \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.3:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}xdg>=0.25:devel/py-xdg

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
