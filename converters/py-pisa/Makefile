# Created by: Wen Heping <wenheping@wenheping.com>
# $FreeBSD$

PORTNAME=	pisa
PORTVERSION=	3.0.33
PORTREVISION=	2
CATEGORIES=	converters python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	PDF generator using HTML and CSS

LICENSE=	APACHE20

DEPRECATED=	Deprecated upstream, depends on broken and expired py-reportlab2
EXPIRATION_DATE=	2016-12-08

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>=0.11.1:www/py-html5lib \
		${PYTHON_PKGNAMEPREFIX}reportlab2>=2.1:print/py-reportlab2 \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}pdf>=1.12:print/py-pdf

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
