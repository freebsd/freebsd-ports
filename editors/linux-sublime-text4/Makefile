PORTNAME=	sublime-text4
PORTVERSION=	4200
CATEGORIES=	editors linux
MASTER_SITES=	http://download.sublimetext.com/
PKGNAMEPREFIX=	linux-

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Sophisticated text editor for code, markup and prose
WWW=		https://www.sublimetext.com

LICENSE=	SUBLIMEHQ
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	upstream only supports amd64 and aarch64

USES=		desktop-file-utils gnome linux tar:xz
USE_LINUX=	curl gtk3

CONFLICTS_INSTALL=	linux-sublime[0-9]*

NO_BUILD=	yes
SUB_FILES=	sublime-text

WRKSRC=		${WRKDIR}/sublime_text

DISTNAME_amd64=	sublime_text_build_${PORTVERSION}_x64
DISTNAME_aarch64=	sublime_text_build_${PORTVERSION}_arm64

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
	${INSTALL_SCRIPT} ${WRKDIR}/sublime-text ${STAGEDIR}${PREFIX}/bin/sublime_text

.include <bsd.port.mk>
