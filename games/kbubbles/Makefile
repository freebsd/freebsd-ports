# New ports collection makefile for:	kbubbles
# Date created:		15 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kbubbles
PORTVERSION=	0.8.6
CATEGORIES=	games
MASTER_SITES=	http://hem.passagen.se/tonybj/kbubbles/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	QwSpriteField.7:${PORTSDIR}/converters/kdesupport11

USE_KDELIBS_VER=1
USE_LIBTOOL=	yes

.include <bsd.port.mk>
