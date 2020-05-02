# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	poppler
PORTVERSION=	0.12.1
PORTREVISION=	21
CATEGORIES=	graphics python
MASTER_SITES=	https://launchpad.net/poppler-python/trunk/development/+download/ \
		http://launchpadlibrarian.net/30270080/ \
		http://romain.blogreen.org/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Python bindings for the Poppler PDF rendering library

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib

GNU_CONFIGURE=	yes
USES=		gmake gnome libtool pkgconfig python:2.7
USE_GNOME=	atk pygtk2
USE_PYTHON=	flavors

.include <bsd.port.mk>
