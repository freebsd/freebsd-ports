# New ports collection makefile for:	xmms-mailnotify
# Date created:			03.02.2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	xmms-mailnotify
PORTVERSION=	0.2.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	arved@FreeBSD.org
COMMENT=	"XMMS plugin, that plays a sound on incoming mail and opens the MUA"

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=	13
USE_GMAKE=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib,${X11BASE}/lib," ${WRKSRC}/mailnotify.c

.include <bsd.port.mk>
