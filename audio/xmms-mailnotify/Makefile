# New ports collection makefile for:	xmms-mailnotify
# Date created:			03.02.2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	xmms-mailnotify
PORTVERSION=	0.2.0
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	arved@FreeBSD.org
COMMENT=	XMMS plugin, that plays a sound on incoming mail and opens the MUA

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_LDCONFIG=	yes

PLIST_FILES=	lib/xmms/General/libmailnotify.so \
		lib/xmms/General/alert.wav

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib,${LOCALBASE}/lib," ${WRKSRC}/mailnotify.c

.include <bsd.port.mk>
