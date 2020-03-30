# Created by: Alexander Vereeken <Alexander88207@protonmail.com>
# $FreeBSD$

PORTNAME=	homura
PORTVERSION=	3.6
CATEGORIES=	games

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Windows Games Launcher for FreeBSD

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Wine only runs on x86 architecture

RUN_DEPENDS=	zenity:x11/zenity \
		xdg-open:devel/xdg-utils \
		bash:shells/bash \
		7z:archivers/p7zip \
		webfonts>=0:x11-fonts/webfonts \
		winetricks:emulators/winetricks \
		vulkaninfo:devel/vulkan-tools \
		glxinfo:graphics/mesa-demos

USE_GITHUB=	yes
GH_ACCOUNT=	the-homura-project

NO_BUILD=	yes

PLIST_FILES=	bin/Homura \
		share/homura/Data/Apps.hma \
		share/homura/Data/Setups.hma \
		share/homura/Data/Misc.hma \
		share/homura/Data/Checks.hma

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
RUN_DEPENDS+=	wine:emulators/wine-devel
.else
RUN_DEPENDS+=	wine:emulators/i386-wine-devel
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/homura/Data
	${INSTALL_SCRIPT} ${WRKSRC}/Homura ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Data/Apps.hma ${STAGEDIR}${PREFIX}/share/homura/Data
	${INSTALL_SCRIPT} ${WRKSRC}/Data/Setups.hma ${STAGEDIR}${PREFIX}/share/homura/Data
	${INSTALL_SCRIPT} ${WRKSRC}/Data/Misc.hma ${STAGEDIR}${PREFIX}/share/homura/Data
	${INSTALL_SCRIPT} ${WRKSRC}/Data/Checks.hma ${STAGEDIR}${PREFIX}/share/homura/Data

.include <bsd.port.post.mk>
