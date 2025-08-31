PORTNAME=	quilter
DISTVERSION=	3.3.4
PORTREVISION=	2
CATEGORIES=	editors

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Editor allowing you to focus on your writing
WWW=		https://github.com/lainsce/quilter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	discount>0:textproc/discount
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40 \
		libhandy-1.so:x11-toolkits/libhandy

USES=		compiler:c11 desktop-file-utils gettext gnome meson pkgconfig python:build vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	lainsce
USE_GNOME=	glib20 gtk30 gtksourceview4

LDFLAGS+=	${LOCALBASE}/lib/libmarkdown.a

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
