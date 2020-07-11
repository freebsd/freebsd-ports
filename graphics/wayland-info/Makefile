# $FreeBSD$

PORTNAME=	wayland-info
PORTVERSION=	s20200709
CATEGORIES=	graphics

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	e95b23f7430b.diff:-p1 # https://gitlab.freedesktop.org/ofourdan/wayland-info/-/merge_requests/2

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Display information about protocols supported by Wayland compositor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	wayland-protocols>=1.18:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	ofourdan
GL_COMMIT=	f7f4e42ed46200b4bf1c1df4d26ee8f4b532439a
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
