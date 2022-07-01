# Created by: Emmanuel Vadot <manu@FreeBSD.org>

PORTNAME=	havoc
PORTVERSION=	0.3.1
CATEGORIES=	deskutils wayland

PATCH_SITES=		https://github.com/ii8/havoc/commit/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	manu@FreeBSD.org
COMMENT=	Minimal terminal emulator for Wayland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
		libxkbcommon>0:x11/libxkbcommon
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSansMono.ttf:x11-fonts/dejavu

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ii8
GH_PROJECT=	havoc

PATCHFILES+=		be024469f0.patch # https://github.com/ii8/havoc/pull/32
PATCHFILES+=		4fe53499c6.patch # https://github.com/ii8/havoc/pull/32
PATCHFILES+=		f7bcc3d158.patch # https://github.com/ii8/havoc/pull/32
PATCHFILES+=		ef6eff8681.patch # https://github.com/ii8/havoc/pull/32

PLIST_FILES=	bin/havoc \
		share/examples/havoc/havoc.cfg

SUB_FILES=	pkg-message

do-build:
	(cd ${WRKSRC} && ${MAKE_CMD} havoc)

do-install:
	(cd ${WRKSRC} && ${MAKE_CMD} PREFIX=${STAGEDIR}${PREFIX} install)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/havoc.cfg ${STAGEDIR}${EXAMPLESDIR}/havoc.cfg
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/havoc

.include <bsd.port.mk>
