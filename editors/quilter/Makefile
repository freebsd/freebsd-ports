# $FreeBSD$

PORTNAME=	quilter
DISTVERSION=	2.2.0
CATEGORIES=	editors

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Editor allowing you to focus on your writing

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	valac:lang/vala \
		discount>0:textproc/discount
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		compiler:c11 desktop-file-utils gettext gnome meson pkgconfig python:build
USE_GITHUB=	yes
GH_ACCOUNT=	lainsce
USE_GNOME=	glib20 gtk30 gtksourceview3

INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	com.github.lainsce.quilter.gschema.xml

LDFLAGS+=	${LOCALBASE}/lib/libmarkdown.a

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
