# $FreeBSD$

PORTNAME=	swappy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Snapshot editing for Wayland (a la Snappy on macOS)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 desktop-file-utils gettext-tools gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30
GH_ACCOUNT=	jtheoof
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/locale/de/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/en/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/pt_BR/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/tr/LC_MESSAGES/${PORTNAME}.mo \
		${NULL}

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	CLIPBOARD ICONSFONT MANPAGES
OPTIONS_DEFAULT=CLIPBOARD ICONSFONT MANPAGES

CLIPBOARD_DESC=		Copy to clipboard support
CLIPBOARD_RUN_DEPENDS=	wl-copy:x11/wl-clipboard

ICONSFONT_DESC=		Install Font Awesome to properly render icons
ICONSFONT_RUN_DEPENDS=	font-awesome>0:x11-fonts/font-awesome

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
