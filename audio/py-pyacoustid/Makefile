# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyacoustid
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Bindings for Chromaprint acoustic fingerprinting and the Acoustid API

LICENSE=	MIT

LIB_DEPENDS=	libchromaprint.so:${PORTSDIR}/audio/chromaprint

USE_PYTHON=	yes
NO_STAGE=	yes
USE_PYDISTUTILS=	easy_install
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
