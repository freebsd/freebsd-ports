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

MAINTAINER=	will@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	QwSpriteField.7:${PORTSDIR}/converters/kdesupport11 \
		kdecore.3:${PORTSDIR}/x11/kdelibs11

USE_LIBTOOL=	yes
USE_QT=		yes

.include <bsd.port.mk>
