# New ports collection makefile for:	bmp-wma
# Date created:		2004-07-16
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	bmp-wma
PORTVERSION=	0.1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.nixp.ru/pub/files/ \
		http://bmpwma.younggods.net/download/

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	WMA input plugin for beep-media-player

LIB_DEPENDS=	beep.1:${PORTSDIR}/multimedia/beep-media-player

PLIST_FILES=	lib/bmp/Input/libwma.so

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
