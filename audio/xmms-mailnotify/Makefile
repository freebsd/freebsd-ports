# New ports collection makefile for:	xmms-mailnotify
# Date created:			03.02.2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	xmms-mailnotify
PORTVERSION=	0.2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://iso.kapsobor.de/xmms/
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	arved@FreeBSD.org

LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
