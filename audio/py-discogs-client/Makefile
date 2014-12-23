# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	discogs-client
PORTVERSION=	2.0.2
PORTREVISION=	0
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Python interface to Discogs website

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}oauth2>=0:${PORTSDIR}/net/py-oauth2

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
