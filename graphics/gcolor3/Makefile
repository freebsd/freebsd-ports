PORTNAME=	gcolor3
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	graphics

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	1750369a3fd9.patch:-p1 # https://gitlab.gnome.org/World/gcolor3/-/merge_requests/151

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Colour picker is a simple color chooser
WWW=		https://www.hjdskes.nl/projects/gcolor3/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libportal-gtk3.so:deskutils/libportal

USES=		gnome gettext meson libtool pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_COMMIT=	7053f9e6a890175fc212df625e02ffbdce418146
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool

MESON_ARGS=	-Dwerror=false

.include <bsd.port.mk>
