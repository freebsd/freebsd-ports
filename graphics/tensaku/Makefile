PORTNAME=	tensaku
DISTVERSIONPREFIX=	v
DISTVERSION=	0.29.0
CATEGORIES=	graphics wayland

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Screenshot annotation tool for Wayland
WWW=		https://github.com/jondkinney/tensaku

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libgraphene-1.0.so:graphics/graphene \
		libgtk4-layer-shell.so:x11-toolkits/gtk4-layer-shell \
		libxkbcommon.so:x11/libxkbcommon

USES=		cargo desktop-file-utils gnome pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	jondkinney
USE_GNOME=	cairo gdkpixbuf glib20 gtk40 libadwaita pango

SHEBANG_FILES=	assets/tensaku-edit

CARGO_FEATURES=	ci-release
CARGO_INSTALL_PATH=	.

PLIST_FILES=	bin/tensaku \
		bin/tensaku-edit \
		share/applications/dev.tensaku.Tensaku.desktop \
		share/bash-completion/completions/tensaku \
		share/fish/vendor_completions.d/tensaku.fish \
		share/icons/hicolor/scalable/apps/dev.tensaku.Tensaku.svg \
		share/man/man1/tensaku.1.gz \
		share/zsh/site-functions/_tensaku

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/assets/tensaku-edit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dev.tensaku.Tensaku.desktop ${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/assets/tensaku.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/dev.tensaku.Tensaku.svg
	${INSTALL_MAN} ${WRKSRC}/man/tensaku.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/tensaku.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/tensaku
	${INSTALL_DATA} ${WRKSRC}/completions/tensaku.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/completions/_tensaku \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
