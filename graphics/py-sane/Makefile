# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	sane
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://effbot.org/media/downloads/ \
		http://www.pythonware.net/storage/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Imaging-1.1.7

MAINTAINER=	buganini@gmail.com
COMMENT=	Python bindings for Sane

LIB_DEPENDS=	libsane.so:graphics/sane-backends
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow

DIST_SUBDIR=	python
USES=		python
USE_PYTHON=	distutils

WRKSRC=		${WRKDIR}/${DISTNAME}/Sane

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
