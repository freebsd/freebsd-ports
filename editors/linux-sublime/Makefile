# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	sublime
PORTVERSION=	2.0.2
PORTREVISION=	6
CATEGORIES=	editors linux
MASTER_SITES=	https://download.sublimetext.com/
DISTNAME=	Sublime%20Text%202.0.2
PKGNAMEPREFIX=	linux-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sophisticated text editor for code, markup and prose

INSTALLS_ICONS=	yes
USES=		desktop-file-utils gnome linux tar:bzip2
USE_LINUX=	xorglibs gtk2
WRKSRC=		${WRKDIR}/"Sublime Text 2"

NO_BUILD=
SUB_FILES=	sublime

CONFLICTS_INSTALL=	linux-sublime3-[0-9]*

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	@${INSTALL_DATA} ${FILESDIR}/sublime_text.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/Icon/16x16/sublime_text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/
	@${INSTALL_DATA} ${WRKSRC}/Icon/32x32/sublime_text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/
	@${INSTALL_DATA} ${WRKSRC}/Icon/48x48/sublime_text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/
	@${INSTALL_DATA} ${WRKSRC}/Icon/128x128/sublime_text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/
	@${INSTALL_DATA} ${WRKSRC}/Icon/256x256/sublime_text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/
	@${RM} -r ${WRKSRC}/Icon/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	@${CHMOD} +x ${STAGEDIR}${DATADIR}/sublime_text
	@${INSTALL_SCRIPT} ${WRKDIR}/sublime ${STAGEDIR}${PREFIX}/bin/sublime

.include <bsd.port.mk>
