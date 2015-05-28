# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=		django-tastypie-mongoengine
PORTVERSION=		0.4.6
DISTVERSIONPREFIX=	v
CATEGORIES=		devel
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		dvl@FreeBSD.org
COMMENT=		MongoEngine support for django-tastypie

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=		yes
GH_ACCOUNT=		wlanslovenija

USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_SINGLE=		DJANGO
OPTIONS_SINGLE_DJANGO=	DJANGO16 DJANGO17
OPTIONS_DEFAULT=	DJANGO17

DJANGO16_DESC=	Build with Django 1.6
DJANGO17_DESC=	Build with Django 1.7

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}django-tastypie>=0.9.12:${PORTSDIR}/www/py-django-tastypie \
		${PYTHON_PKGNAMEPREFIX}mongoengine>=0.8.7:${PORTSDIR}/devel/py-mongoengine

DJANGO16_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django16>0:${PORTSDIR}/www/py-django16
DJANGO17_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>0:${PORTSDIR}/www/py-django

.include <bsd.port.mk>
