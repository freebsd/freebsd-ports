PORTNAME=	mepo
DISTVERSION=	1.4.0
CATEGORIES=	astro geography wayland

MAINTAINER=	kenrap@FreeBSD.org
COMMENT=	Fast, simple, and hackable OSM map viewer
WWW=		https://sr.ht/~mil/Mepo/

LICENSE=	GPLv3+ OFL11
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	jq:textproc/jq

USES=		pkgconfig sdl shebangfix zig

USE_GITHUB=	yes
GH_ACCOUNT=	kenrap

USE_SDL=	gfx2 image2 ttf2
SHEBANG_FILES=	scripts/*
SHEBANG_LANG=	sh
sh_CMD=		/bin/sh

post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},' \
		${WRKSRC}/scripts/mepo_ui_menu_user_pin_updater.sh
	@${REINPLACE_CMD} -e 's/pidof/pgrep/' \
		-e 's/busctl/basuctl/' \
		${WRKSRC}/scripts/mepo_ui_helper_menu.sh

do-test:
	@(cd ${WRKSRC} && ${TEST_ENV} zig build test ${CONFIGURE_ARGS})

.include <bsd.port.mk>
