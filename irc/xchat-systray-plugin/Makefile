# New ports collection makefile for:	xchat-systray-plugin
# Date Created:				Nov 04 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	xchat-systray-plugin
PORTVERSION=	2.4.5
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xchat2-plugins
DISTNAME=	xchat-systray-integration-${PORTVERSION}-src

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Systray icon plugin for X-Chat

RUN_DEPENDS=	xchat:${PORTSDIR}/irc/xchat2

WRKSRC=		${WRKDIR}/xchat-systray-integration-${PORTVERSION}
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-Os|${CFLAGS} -fPIC|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/systray.so ${PREFIX}/lib/xchat/plugins/
	${MKDIR} ${PREFIX}/lib/xchat/plugins/GTKTray
	${INSTALL_DATA} ${WRKSRC}/src/images/GTKTray/* ${PREFIX}/lib/xchat/plugins/GTKTray
	${MKDIR} ${PREFIX}/lib/xchat/plugins/Menu
	${INSTALL_DATA} ${WRKSRC}/src/images/Menu/* ${PREFIX}/lib/xchat/plugins/Menu

.include <bsd.port.mk>
