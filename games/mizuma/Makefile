PORTNAME=	mizuma
DISTVERSION=	2024.11
CATEGORIES=	games emulators
MASTER_SITES=	https://codeberg.org/Alexander88207/Mizutamari/archive/${PORTVERSION}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Wine front-end for FreeBSD
WWW=		https://codeberg.org/Alexander88207/Mizutamari

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

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/mizutamari

PLIST_FILES=	bin/Mizuma \
		share/Mizutamari/Tools/Framework

OPTIONS_DEFAULT=	GLX_UTILS
OPTIONS_RADIO=		GLXINFO
OPTIONS_RADIO_GLXINFO=	GLX_UTILS MESA_DEMOS
OPTIONS_SUB=		yes

GLX_UTILS_DESC=		Use glxinfo from glx-utils
MESA_DEMOS_DESC=	Use glxinfo from mesa-demos

GLX_UTILS_RUN_DEPENDS=	glxinfo:graphics/glx-utils
MESA_DEMOS_RUN_DEPENDS=	glxinfo:graphics/mesa-demos

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/Mizutamari/Tools
	${INSTALL_SCRIPT} ${WRKSRC}/Mizuma ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Tools/Framework ${STAGEDIR}${PREFIX}/share/Mizutamari/Tools

.include <bsd.port.mk>
