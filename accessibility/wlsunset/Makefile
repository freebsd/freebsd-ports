# $FreeBSD$

PORTNAME=	wlsunset
DISTVERSION=	0.1.0
CATEGORIES=	accessibility
MASTER_SITES=	https://git.sr.ht/~kennylevinsen/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://git.sr.ht/~kennylevinsen/${PORTNAME}/commit/
PATCHFILES+=	fa2bd4425314.patch:-p1 33c64bc929b2.patch:-p1 # manpage
PATCHFILES+=	ec0c1614af21.patch:-p1 # avoid USES=localbase
PATCHFILES+=	49ad3ce7a8e8.patch:-p1 # unbreak Clang >= 10

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
