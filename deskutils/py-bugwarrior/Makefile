# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bugwarrior
PORTVERSION=	1.1.3
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Sync issue & bug tracking systems with taskwarrior

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twiggy>0:${PORTSDIR}/devel/py-twiggy \
		${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}offtrac>0:${PORTSDIR}/devel/py-offtrac \
		${PYTHON_PKGNAMEPREFIX}python-bugzilla>0:${PORTSDIR}/devel/py-python-bugzilla \
		${PYTHON_PKGNAMEPREFIX}taskw>=0.8:${PORTSDIR}/deskutils/py-taskw \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}keyring>0:${PORTSDIR}/security/py-keyring \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7.2:${PORTSDIR}/devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}curl>0:${PORTSDIR}/ftp/py-curl \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>=0.5.3:${PORTSDIR}/devel/py-dogpile.cache \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0.9.1:${PORTSDIR}/devel/py-lockfile \
		${PYTHON_PKGNAMEPREFIX}click>0:${PORTSDIR}/devel/py-click \
		${PYTHON_PKGNAMEPREFIX}xdg>0:${PORTSDIR}/devel/py-xdg

USES=		python:2
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
