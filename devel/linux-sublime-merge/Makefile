PORTNAME=	sublime-merge
PORTVERSION=	2110
CATEGORIES=	devel linux
MASTER_SITES=	https://download.sublimetext.com/
PKGNAMEPREFIX=	linux-

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Cross-platform Git client, done the Sublime Text way
WWW=		https://www.sublimemerge.com/

LICENSE=	SUBLIMEHQ
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	upstream only supports amd64 and arm64

USES=		desktop-file-utils gnome linux tar:xz
USE_LINUX=	gtk3

NO_BUILD=	yes
SUB_FILES=	sublime-merge

WRKSRC=		${WRKDIR}/sublime_merge

DISTNAME_amd64=	sublime_merge_build_${PORTVERSION}_x64
DISTNAME_aarch64=	sublime_merge_build_${PORTVERSION}_arm64

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/
	${INSTALL_DATA} ${WRKSRC}/Icon/16x16/sublime-merge.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/
	${INSTALL_DATA} ${WRKSRC}/Icon/32x32/sublime-merge.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/
	${INSTALL_DATA} ${WRKSRC}/Icon/48x48/sublime-merge.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/
	${INSTALL_DATA} ${WRKSRC}/Icon/128x128/sublime-merge.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/
	${INSTALL_DATA} ${WRKSRC}/Icon/256x256/sublime-merge.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/
	${INSTALL_DATA} ${WRKSRC}/sublime_merge.desktop ${STAGEDIR}${PREFIX}/share/applications/
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/sublime-merge ${STAGEDIR}${PREFIX}/bin/sublime_merge

.include <bsd.port.mk>
