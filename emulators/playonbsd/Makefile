PORTNAME=	playonbsd
PORTVERSION=	4.2.10
PORTREVISION=	11
CATEGORIES=	emulators games

MAINTAINER=	Clockwork6400@protonmail.com
COMMENT=	Easily install and run Windows software for use with Wine
WWW=		https://github.com/Clockwork6400/POL-FreeBSD-4

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	7z:archivers/7-zip \
		bash:shells/bash \
		cabextract:archivers/cabextract \
		glxinfo:graphics/mesa-demos \
		gpg:security/gnupg \
		gsed:textproc/gsed \
		icotool:graphics/icoutils \
		jq:textproc/jq \
		sudo:security/sudo \
		wget:ftp/wget \
		xdg-open:devel/xdg-utils \
		xterm:x11/xterm

USES=		perl5 python:run shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	Clockwork6400
GH_PROJECT=	POL-FreeBSD-4
USE_WX=		3.2
WX_COMPS=	python:run
SHEBANG_FILES=	bash/expert/* lib/*
SHEBANG_GLOB=	*.py
NO_ARCH=	yes

OPTIONS_DEFINE=		GECKO MONO NLS
OPTIONS_DEFAULT=	GECKO MONO WINE
OPTIONS_RADIO=		WINE
OPTIONS_RADIO_WINE=	WINE WINE_DEVEL
OPTIONS_SUB=		yes

GECKO_DESC=		Wine-gecko HTML rendering support
WINE_DESC=		Installing Wine Emulator dependencies
WINE_DEVEL_DESC=	Installing Wine-devel emulator dependencies
GECKO_RUN_DEPENDS=	wine-gecko>=2.47.1:emulators/wine-gecko
MONO_RUN_DEPENDS=	wine-mono>=4.9.4:emulators/wine-mono
NLS_USES=		gettext
WINE_RUN_DEPENDS=	wine:emulators/wine
WINE_DEVEL_RUN_DEPENDS=	wine:emulators/wine-devel

.include <bsd.port.pre.mk>

NO_BUILD=	true
SUB_FILES=	playonbsd.sh

do-install:
.for d in bash python
		cd ${WRKSRC} && ${COPYTREE_BIN} ${d} ${STAGEDIR}${PREFIX}/lib/playonbsd/ "! -name *\.orig ! -name *\.bak"
.endfor
.for d in etc lib plugins resources
		cd ${WRKSRC} && ${COPYTREE_BIN} ${d} ${STAGEDIR}${PREFIX}/lib/playonbsd/ "! -name *\.orig ! -name *\.bak"
.endfor
		@${REINPLACE_CMD} -e 's:linux:bsd:g;s:linux:BSD:ig' ${WRKSRC}/doc/playonlinux.1
		${INSTALL_MAN} ${WRKSRC}/doc/playonlinux.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/playonbsd.1
		${INSTALL_SCRIPT} ${WRKDIR}/playonbsd.sh ${STAGEDIR}${PREFIX}/bin/playonbsd
		${INSTALL_SCRIPT} ${WRKSRC}/playonfreebsd ${STAGEDIR}${PREFIX}/lib/playonbsd/playonfreebsd
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/playonbsd/lang/locale/en_GB/LC_MESSAGES
		${INSTALL_SCRIPT} ${WRKSRC}/lang/locale/en_GB/LC_MESSAGES/pol.mo ${STAGEDIR}${PREFIX}/lib/playonbsd/lang/locale/en_GB/LC_MESSAGES/pol.mo
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/playonbsd/lang/po
		${INSTALL_SCRIPT} ${WRKSRC}/lang/po/en_GB.po ${STAGEDIR}${PREFIX}/lib/playonbsd/lang/po/en_GB.po

post-install-NLS-on:
		cd ${WRKSRC} && ${COPYTREE_BIN} lang ${STAGEDIR}${PREFIX}/lib/playonbsd/ "! -name *\.orig ! -name *\.bak"

.include <bsd.port.post.mk>
