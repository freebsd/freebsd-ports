# New ports collection makefile for:	bmp-rootvis
# Date created:		2004-10-15
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	bmp-rootvis
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.berlios.de/bmp-plugins/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	BMP plugin which renders a spectrum analyzer on the root window

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player

PLIST_FILES=	lib/bmp/Visualization/librootvis.so

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
