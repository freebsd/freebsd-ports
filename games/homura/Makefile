# Created by: Alexander Vereeken <Alexander88207@protonmail.com>
# $FreeBSD$

PORTNAME=	homura
PORTVERSION=	5.3
CATEGORIES=	games
MASTER_SITES=	https://codeberg.org/Alexander88207/Homura/archive/
DISTNAME=	${PORTVERSION}

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
		winetricks:emulators/winetricks \
		vulkaninfo:graphics/vulkan-tools \
		glxinfo:graphics/mesa-demos

WRKSRC=	${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

PLIST_FILES=	bin/Homura

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
RUN_DEPENDS+=	wine:emulators/wine-devel
.else
RUN_DEPENDS+=	wine:emulators/i386-wine-devel
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Homura ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
