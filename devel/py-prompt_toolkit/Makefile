# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	prompt_toolkit
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Library for building powerful interactive command lines in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>=0.6.2:${PORTSDIR}/devel/py-docopt \
		${PYTHON_PKGNAMEPREFIX}six>=1.7.3:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.6:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}jedi>=0.8.1:${PORTSDIR}/devel/py-jedi

USES=	python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
