# New ports collection makefile for:	xchat-systray-plugin
# Date Created:				Nov 04 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	xchat-systray-plugin
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xchat2-plugins
DISTNAME=	xchat-systray-integration-${PORTVERSION}-src

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Systray icon plugin for X-Chat

RUN_DEPENDS=	xchat:${PORTSDIR}/irc/xchat2

PLIST_FILES=	lib/xchat/plugins/systray.so
WRKSRC=		${WRKDIR}/xchat-systray-integration-${PORTVERSION}
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS} -fPIC|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/systray.so ${X11BASE}/lib/xchat/plugins/

.include <bsd.port.mk>
