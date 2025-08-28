PORTNAME=	swappy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
CATEGORIES=	graphics wayland
MASTER_SITES=	https://github.com/jtheoof/${PORTNAME}/releases/download/${DISTVERSIONFULL}/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Snapshot editing for Wayland (a la Snappy on macOS)
WWW=		https://github.com/jtheoof/swappy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 desktop-file-utils gettext-tools gnome meson \
		pkgconfig

USE_GNOME=	cairo gdkpixbuf gtk30

OPTIONS_DEFINE=	CLIPBOARD ICONSFONT MANPAGES
OPTIONS_DEFAULT=CLIPBOARD ICONSFONT MANPAGES
OPTIONS_SUB=	yes

CLIPBOARD_DESC=		Copy to clipboard support
ICONSFONT_DESC=		Install Font Awesome to properly render icons

CLIPBOARD_RUN_DEPENDS=	wl-copy:x11/wl-clipboard

ICONSFONT_RUN_DEPENDS=	font-awesome>0:x11-fonts/font-awesome

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages

.include <bsd.port.mk>
