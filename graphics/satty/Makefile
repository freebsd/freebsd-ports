PORTNAME=	satty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.1
CATEGORIES=	graphics wayland
MASTER_SITES=	CRATESIO

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Modern screenshot annotation
WWW=		https://github.com/gabm/Satty

LICENSE=	MPL20

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		cargo desktop-file-utils gnome
USE_GITHUB=	yes
USE_GNOME=	gdkpixbuf gtk40 libadwaita
GH_ACCOUNT=	gabm
GH_PROJECT=	Satty
CARGO_FEATURES=	ci-release
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/bash-completion/completions/${PORTNAME} \
		share/elvish/lib/${PORTNAME}.elv \
		share/fig/autocomplete/${PORTNAME}.ts \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/man/man1/${PORTNAME}.1.gz \
		share/nushell/completions/${PORTNAME}.nu \
		share/zsh/site-functions/_${PORTNAME}

post-install:
# Install assets similar to vendor Makefile
.for f in *.desktop assets/*.svg
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}:H}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.${f:E}}
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/* \
		${PLIST_FILES:M*/man/*:R:S,^,${STAGEDIR}${PREFIX}/,}
.for f in bash-completion:*.bash elvish:*.elv fish:*.fish fig:*.ts nushell:*.nu zsh:_*
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*${f:C/:.*//}*:H}
	${INSTALL_DATA} ${WRKSRC}/completions/${f:C/.*://} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M*${f:C/:.*//}*}
.endfor

.include <bsd.port.mk>
