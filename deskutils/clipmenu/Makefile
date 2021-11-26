# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>

PORTNAME=	clipmenu
DISTVERSION=	6.2.0
PORTREVISION=	0
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Clipboard management using dmenu, rofi or fzf

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		clipnotify:deskutils/clipnotify \
		flock:sysutils/flock \
		xsel:x11/xsel-conrad

USES=		xorg

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/clipctl bin/clipdel bin/clipfsck bin/clipmenu bin/clipmenud

OPTIONS_DEFAULT=	DMENU
OPTIONS_SINGLE=	LAUNCHER
OPTIONS_SINGLE_LAUNCHER=	DMENU FZF ROFI

DMENU_DESC=	Use dmenu to show clipboard selections
FZF_DESC=	Use fzf to manage clipboard selections
ROFI_DESC=	Use rofi to show clipboard selections

DMENU_RUN_DEPENDS=	dmenu:x11/dmenu
FZF_RUN_DEPENDS=	fzf:textproc/fzf
ROFI_RUN_DEPENDS=	rofi:x11/rofi

USE_XORG=	x11 xfixes

USE_GITHUB=	yes
GH_ACCOUNT=	cdown

post-extract:
	@${REINPLACE_CMD} -e '3s,dmenu,${SELECTED_OPTIONS:tl},1' ${WRKSRC}/clipmenu

do-install:
	@cd ${WRKSRC} && ${INSTALL_SCRIPT} clipctl clipdel clipfsck clipmenu clipmenud \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
