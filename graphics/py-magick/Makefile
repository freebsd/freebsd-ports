# New ports collection makefile for:	py-magick
# Date created:		2 November 2003
# Whom:			Tim Hemel <tim@n2it.net>
#
# $FreeBSD$
#

PORTNAME=	magick
PORTVERSION=	0.5
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pylab
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}
DISTNAME=	magick-${PORTVERSION}

MAINTAINER=	tim@n2it.net
COMMENT=	Python bindings for ImageMagick

BUILD_DEPENDS=	${PYNUMERIC}
RUN_DEPENDS=	${PYNUMERIC}
LIB_DEPENDS=	Magick.6:${PORTSDIR}/graphics/ImageMagick

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/magick.so
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
