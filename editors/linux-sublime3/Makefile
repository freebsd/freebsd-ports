PORTNAME=	sublime
PORTVERSION=	3.2.2
PORTREVISION=	2
CATEGORIES=	editors linux
MASTER_SITES=	http://download.sublimetext.com/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	3

MAINTAINER=	matias@pizarro.net
COMMENT=	Sophisticated text editor for code, markup and prose

LICENSE=	SUBLIMEHQ
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	upstream only supports amd64 and i386

USES=		desktop-file-utils gnome linux tar:bzip2
USE_LINUX=	gtk3

CONFLICTS_INSTALL=	linux-sublime[0-9]*

NO_BUILD=	yes
SUB_FILES=	sublime

WRKSRC=		${WRKDIR}/sublime_text_3

DISTNAME_amd64=	sublime_text_3_build_3211_x64
DISTNAME_i386=	sublime_text_3_build_3211_x32

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for res in 16 32 48 128 256
	@${MKDIR} \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${res}x${res}/apps/
	${INSTALL_DATA} ${WRKSRC}/Icon/${res}x${res}/sublime-text.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${res}x${res}/apps/
.endfor
	${INSTALL_DATA} ${WRKSRC}/sublime_text.desktop ${STAGEDIR}${PREFIX}/share/applications/
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/sublime ${STAGEDIR}${PREFIX}/bin/sublime

.include <bsd.port.mk>
