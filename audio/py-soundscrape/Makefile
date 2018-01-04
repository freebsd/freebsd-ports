# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	soundscrape
PORTVERSION=	0.30.1
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	SoundCloud downloader in python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=1.31.0:audio/py-mutagen@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soundcloud>=0.4.1:audio/py-soundcloud@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}args>=0.1.0:devel/py-args@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}clint>=0.3.2:devel/py-clint@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}demjson>=2.2.2:devel/py-demjson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fudge>=1.0.3:devel/py-fudge@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=1.3.7:devel/py-nose@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=3.3.1:devel/py-simplejson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.24.0:devel/py-wheel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.9.0:www/py-requests@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
