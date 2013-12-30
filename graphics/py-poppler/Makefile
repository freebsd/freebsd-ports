# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	poppler
PORTVERSION=	0.12.1
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	https://launchpad.net/poppler-python/trunk/development/+download/ \
		http://launchpadlibrarian.net/30270080/ \
		http://romain.blogreen.org/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Python bindings for the Poppler PDF rendering library

LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	atk pygtk2

NO_STAGE=	yes
.include <bsd.port.mk>
