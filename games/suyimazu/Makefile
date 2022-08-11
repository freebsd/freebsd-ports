PORTNAME=	suyimazu
DISTVERSION=	5.8
CATEGORIES=	games
MASTER_SITES=	https://codeberg.org/Alexander88207/Suyimazu/archive/
DISTNAME=	${DISTVERSION}

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Wine-based Game Launcher for FreeBSD

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Wine only runs on x86 architecture

RUN_DEPENDS=	7zz:archivers/7-zip \
		bash:shells/bash \
		glxinfo:graphics/glx-utils \
		vulkaninfo:graphics/vulkan-tools \
		wine-proton>0:emulators/wine-proton \
		winetricks:emulators/winetricks \
		xdg-open:devel/xdg-utils \
		zenity:x11/zenity

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/Suyimazu \
		share/Suyimazu/Data/Framework

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/Suyimazu/Data
	${INSTALL_SCRIPT} ${WRKSRC}/Suyimazu ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Data/Framework ${STAGEDIR}${PREFIX}/share/Suyimazu/Data

.include <bsd.port.mk>
