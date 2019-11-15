# Created by: Miguel Clara <miguelmclara@gmail.com>
# $FreeBSD$

PORTNAME=	sublime
PORTVERSION=	3.2.2
CATEGORIES=	editors linux
MASTER_SITES=	http://download.sublimetext.com/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	3
DISTNAME_amd64=	sublime_text_3_build_3211_x64
DISTNAME_i386=	sublime_text_3_build_3211_x32

MAINTAINER=	miguelmclara@gmail.com
COMMENT=	Sophisticated text editor for code, markup and prose

USES=		desktop-file-utils gnome linux tar:bzip2
USE_LINUX=	gtk3

INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/sublime_text_3

CONFLICTS_INSTALL=	linux-sublime-[0-9]*

NO_BUILD=	yes
SUB_FILES=	sublime

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/ \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/ \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/ \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/ \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/

	${INSTALL_DATA} ${WRKSRC}/Icon/16x16/sublime-text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/
	${INSTALL_DATA} ${WRKSRC}/Icon/32x32/sublime-text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/
	${INSTALL_DATA} ${WRKSRC}/Icon/48x48/sublime-text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/
	${INSTALL_DATA} ${WRKSRC}/Icon/128x128/sublime-text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/
	${INSTALL_DATA} ${WRKSRC}/Icon/256x256/sublime-text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/
	${INSTALL_DATA} ${WRKSRC}/sublime_text.desktop ${STAGEDIR}${PREFIX}/share/applications/
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/sublime ${STAGEDIR}${PREFIX}/bin/sublime

.include <bsd.port.mk>
