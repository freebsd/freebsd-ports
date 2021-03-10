# Created by: Alexander Vereeken <Alexander88207@protonmail.com>
# $FreeBSD$

PORTNAME=	homura
PORTVERSION=	5.4
CATEGORIES=	games
MASTER_SITES=	https://codeberg.org/Alexander88207/Homura/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Wine-based Game Launcher for FreeBSD

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_13=	i386-wine-(devel) is in a bad condition for 13 and newer builds segfaults
BROKEN_FreeBSD_14=	i386-wine-(devel) segfaults on 14
ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Wine only runs on x86 architecture

RUN_DEPENDS=	7z:archivers/p7zip \
		bash:shells/bash \
		glxinfo:graphics/mesa-demos \
		vulkaninfo:graphics/vulkan-tools \
		winetricks:emulators/winetricks \
		xdg-open:devel/xdg-utils \
		zenity:x11/zenity

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

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
