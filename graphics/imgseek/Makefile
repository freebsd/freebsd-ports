# New ports collection makefile for:	imgseek
# Date created:		16 June 2003
# Whom:			Ben Haga <tuxsuximus@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	imgSeek
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	imgseek
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	freebsd@unixfreunde.de
COMMENT=	A photo manager and viewer with content-based search

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt \
		Magick++-config:${PORTSDIR}/graphics/ImageMagick

USE_CONFIGURE=	no
USE_PYDISTUTILS=	yes
USE_PYTHON=	yes
USE_BZIP2=	yes

#do-build:
#	(cd ${WRKSRC};${PYTHON_CMD} setup.py)
#do-install:

.include <bsd.port.mk>
