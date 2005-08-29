# New ports collection makefile for:	bmp-fc
# Date created:				13 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	bmp-fc
PORTVERSION=	0.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	xmms-fc

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A Future Composer input plug-in for beep-media-player

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/bmp/Input/libfc.so lib/bmp/Input/libfc.la

.include <bsd.port.mk>
