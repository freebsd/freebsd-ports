# New ports collection makefile for:	imgseek
# Date created:		16 June 2003
# Whom:			Ben Haga <tuxsuximus@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	imgSeek
PORTVERSION=	0.8.6
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	alfredoj69@gmail.com
COMMENT=	A photo manager and viewer with content-based search

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		MagickWand.2:${PORTSDIR}/graphics/ImageMagick

USE_PYDISTUTILS=yes
USE_PYTHON=	yes
USE_BZIP2=	yes
USE_QT_VER=	3
MAKE_ENV+=	QTDIR="${QT_PREFIX}"
PYDISTUTILS_NOEGGINFO=	yes

post-patch:
	${REINPLACE_CMD}\
		-e '/^include_dirs =/s|\[\]|["${LOCALBASE}/include"]|'\
		-e '/^library_dirs =/s|\[\]|["${LOCALBASE}/lib"]|'\
		${WRKSRC}/setup.py

.include <bsd.port.mk>
