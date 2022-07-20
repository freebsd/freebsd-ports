PORTNAME=	wlsunset
DISTVERSION=	0.2.0
CATEGORIES=	accessibility wayland
MASTER_SITES=	https://git.sr.ht/~kennylevinsen/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://git.sr.ht/~kennylevinsen/${PORTNAME}/commit/
PATCHFILES+=	601dfc87ff6e.patch:-p1 # https://lists.sr.ht/~kennylevinsen/wlsunset-devel/patches/26904

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Day/night gamma adjustments for Wayland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 meson pkgconfig
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
