# Created by: Miguel Clara <miguelmclara@gmail.com>
# $FreeBSD$

PORTNAME=	sublime
PORTVERSION=	3.0.83
PORTREVISION=	1
CATEGORIES=	editors linux
MASTER_SITES=	http://c758482.r82.cf2.rackcdn.com/
PKGNAMEPREFIX=	linux-
DISTNAME=	sublime_text_3_build_3083_x32

MAINTAINER=	miguelmclara@gmail.com
COMMENT=	Sophisticated text editor for code, markup and prose

USES=		desktop-file-utils tar:bzip2
USE_LINUX=	c6
USE_LINUX_APPS=	xorglibs gtk2

INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/sublime_text_3

CONFLICTS=	linux-sublime-[0-24-9]*

NO_BUILD=
SUB_FILES=	sublime

post-patch:
	${BRANDELF} -t Linux ${WRKSRC}/sublime_text
	${BRANDELF} -t Linux ${WRKSRC}/plugin_host

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
	${CHMOD} +x ${STAGEDIR}${DATADIR}/sublime_text
	${CHMOD} +x ${STAGEDIR}${DATADIR}/plugin_host
	${INSTALL} ${WRKDIR}/sublime ${STAGEDIR}${PREFIX}/bin/sublime

.include <bsd.port.mk>
