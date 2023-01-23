# Created by: Stefan Esser <se@StefanEsser.FreeBSD.org>

PORTNAME=	playonbsd
PORTVERSION=	4.2.10
CATEGORIES=	emulators games

MAINTAINER=	Clockwork6400@protonmail.com
COMMENT=	Easily install and run Windows software for use with Wine

LICENSE=	GPLv3

NO_ARCH=	yes

RUN_DEPENDS=	7z:archivers/7-zip \
		bash:shells/bash \
		glxinfo:graphics/mesa-demos \
		gpg:security/gnupg \
		gsed:textproc/gsed \
		sudo:security/sudo \
		xdg-open:devel/xdg-utils \
		xterm:x11/xterm \
		cabextract:archivers/cabextract \
		wget:ftp/wget \
		icotool:graphics/icoutils \
		jq:textproc/jq

USES=		python:3.9,run perl5 shebangfix
USE_WX=		3.2
WX_COMPS=	python:run
SHEBANG_GLOB=	*.py
SHEBANG_FILES=	bash/expert/* lib/*
USE_GITHUB=	yes
GH_ACCOUNT=	Clockwork6400
GH_PROJECT=	POL-FreeBSD-4

OPTIONS_DEFINE=	GECKO MONO NLS
OPTIONS_DEFAULT=	GECKO MONO WINE
OPTIONS_RADIO=		WINE
OPTIONS_RADIO_WINE=	WINE I386_WINE_DEVEL WINE_DEVEL I386_WINE

GECKO_DESC=	Wine-gecko HTML rendering support
WINE_DESC=	Installing Wine Emulator dependencies
I386_WINE_DEVEL_DESC=	Use your own package/port for i386-wine-devel
WINE_DEVEL_DESC=	Installing Wine-devel emulator dependencies
I386_WINE_DESC=	Use your own package/port for i386-wine
MONO_RUN_DEPENDS=	wine-mono>=4.9.4:emulators/wine-mono
GECKO_RUN_DEPENDS=	wine-gecko>=2.47.1:emulators/wine-gecko
WINE_RUN_DEPENDS=	wine:emulators/wine
I386_WINE_DEVEL_RUN_DEPENDS=	wine:emulators/i386-wine-devel
WINE_DEVEL_RUN_DEPENDS=	wine:emulators/wine-devel
I386_WINE_RUN_DEPENDS=	wine:emulators/i386-wine
NLS_USES=	gettext

.include <bsd.port.pre.mk>

NO_BUILD=	true
SUB_FILES=	playonbsd.sh

do-install:
.for d in bash python
		cd ${WRKSRC} && ${COPYTREE_BIN} ${d} ${STAGEDIR}${PREFIX}/lib/playonbsd/ "! -name *\.orig ! -name *\.bak"
.endfor
.for d in etc lang lib plugins resources
		cd ${WRKSRC} && ${COPYTREE_BIN} ${d} ${STAGEDIR}${PREFIX}/lib/playonbsd/ "! -name *\.orig ! -name *\.bak"
.endfor
		@${REINPLACE_CMD} -e 's:linux:bsd:g;s:linux:BSD:ig' ${WRKSRC}/doc/playonlinux.1
		${INSTALL_MAN} ${WRKSRC}/doc/playonlinux.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/playonbsd.1
		${INSTALL_SCRIPT} ${WRKDIR}/playonbsd.sh ${STAGEDIR}${PREFIX}/bin/playonbsd
		${INSTALL_SCRIPT} ${WRKSRC}/playonfreebsd ${STAGEDIR}${PREFIX}/lib/playonbsd/playonfreebsd

.include <bsd.port.post.mk>
