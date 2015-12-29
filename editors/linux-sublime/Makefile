# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	sublime
PORTVERSION=	2.0.2
PORTREVISION=	3
CATEGORIES=	editors linux
MASTER_SITES=	http://c758482.r82.cf2.rackcdn.com/
DISTNAME=	Sublime%20Text%202.0.2
PKGNAMEPREFIX=	linux-

MAINTAINER=	xmj@chaot.net
COMMENT=	Sublime Text is a sophisticated text editor for code, markup and prose

USES=		tar:bzip2
INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/"Sublime Text 2"

NO_BUILD=
STRIP=		# don't strip linux binaries.
SUB_FILES=	sublime

CONFLICTS_INSTALL=	linux-sublime3-[0-9]*

USE_LINUX=	c6
USE_LINUX_APPS=	xorglibs gtk2

post-patch:
	${BRANDELF} -t Linux ${WRKSRC}/sublime_text

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/

	@${INSTALL_DATA} ${WRKSRC}/Icon/16x16/sublime_text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/
	@${INSTALL_DATA} ${WRKSRC}/Icon/32x32/sublime_text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/
	@${INSTALL_DATA} ${WRKSRC}/Icon/48x48/sublime_text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/
	@${INSTALL_DATA} ${WRKSRC}/Icon/128x128/sublime_text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/
	@${INSTALL_DATA} ${WRKSRC}/Icon/256x256/sublime_text.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/
	@${RM} -rf ${WRKSRC}/Icon/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	@${CHMOD} +x ${STAGEDIR}${DATADIR}/sublime_text
	@${INSTALL} ${WRKDIR}/sublime ${STAGEDIR}${PREFIX}/bin/sublime

.include <bsd.port.mk>
