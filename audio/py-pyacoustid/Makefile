# Created by: Mark Felder <feld@feld.me>
# $FreeBSD$

PORTNAME=	pyacoustid
PORTVERSION=	0.7
CATEGORIES=	audio python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@feld.me
COMMENT=	Bindings for Chromaprint acoustic fingerprinting and the Acoustid API

LICENSE=	MIT

LIB_DEPENDS=	chromaprint:${PORTSDIR}/audio/chromaprint

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/acoustid.py \
		%%PYTHON_SITELIBDIR%%/chromaprint.py

.include <bsd.port.pre.mk>

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} build)

do-install:
	cd ${WRKSRC}/build/lib && ${COPYTREE_SHARE} \* ${PYTHONPREFIX_SITELIBDIR}/

.include <bsd.port.post.mk>
