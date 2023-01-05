PORTNAME=	suyimazu
DISTVERSION=	2023
CATEGORIES=	games
MASTER_SITES=	https://codeberg.org/Alexander88207/Suyimazu/archive/
DISTNAME=	${DISTVERSION}

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Wine-based Game Launcher for FreeBSD
WWW=		https://codeberg.org/Alexander88207/Suyimazu

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Wine only runs on x86 architecture

RUN_DEPENDS=	7zz:archivers/7-zip \
		bash:shells/bash \
		vulkaninfo:graphics/vulkan-tools \
		wine:emulators/wine \
		wine-mono>0:emulators/wine-mono \
		winetricks:emulators/winetricks \
		xdg-open:devel/xdg-utils \
		zenity:x11/zenity

NO_BUILD=	yes

OPTIONS_SUB=	yes
OPTIONS_DEFAULT=	GLX-UTILS
OPTIONS_RADIO=		GLXINFO
OPTIONS_RADIO_GLXINFO=	GLX-UTILS MESA-DEMOS

GLX-UTILS_DESC=		Use glxinfo from glx-utils
MESA-DEMOS_DESC=	Use glxinfo from mesa-demos

GLX-UTILS_RUN_DEPENDS=	glxinfo:graphics/glx-utils
MESA-DEMOS_RUN_DEPENDS=	glxinfo:graphics/mesa-demos

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/Suyimazu \
		share/Suyimazu/Data/Framework

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/Suyimazu/Data
	${INSTALL_SCRIPT} ${WRKSRC}/Suyimazu ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Data/Framework ${STAGEDIR}${PREFIX}/share/Suyimazu/Data

.include <bsd.port.mk>
