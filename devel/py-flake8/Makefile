# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	flake8
PORTVERSION=	2.5.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Code checking using pep8 and pyflakes

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mccabe>=0.2.1:devel/py-mccabe \
		${PYTHON_PKGNAMEPREFIX}pep8>=1.5.7:devel/pep8 \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=0.8.1:devel/py-pyflakes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
