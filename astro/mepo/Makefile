PORTNAME=	mepo
DISTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	astro geography wayland
MASTER_SITES=	https://git.sr.ht/~mil/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Fast, simple, and hackable OSM map viewer
WWW=		https://sr.ht/~mil/Mepo/

LICENSE=	GPLv3+ OFL11
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zig>=0.14.0:lang/zig
LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	jq:textproc/jq

USES=		pkgconfig sdl shebangfix
USE_SDL=	gfx2 image2 ttf2
SHEBANG_FILES=	scripts/*
SHEBANG_LANG=	sh
sh_CMD=		/bin/sh
MAKE_ENV=	DESTDIR="${STAGEDIR}"
CONFIGURE_ARGS=	--prefix "${PREFIX}" \
		${WITH_DEBUG:D:U-Doptimize=ReleaseFast} \
		-Dcpu=${CPUTYPE:Ubaseline} \
		--verbose
NO_INSTALL=	yes # strip(1) breaks runtime

post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},' \
		${WRKSRC}/scripts/mepo_ui_menu_user_pin_updater.sh
	@${REINPLACE_CMD} -e 's/pidof/pgrep/' \
		-e 's/busctl/basuctl/' \
		${WRKSRC}/scripts/mepo_ui_helper_menu.sh

do-build:
	@(cd ${WRKSRC} && ${MAKE_ENV} zig build ${CONFIGURE_ARGS})

do-test:
	@(cd ${WRKSRC} && ${TEST_ENV} zig build test ${CONFIGURE_ARGS})

.include <bsd.port.mk>
