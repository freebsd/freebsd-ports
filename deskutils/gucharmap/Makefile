PORTNAME=	gucharmap
PORTVERSION=	14.0.1
CATEGORIES=	deskutils gnome
#MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	a8ee037f8cf1.patch:-p1 # meson 0.61

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Unicode/ISO10646 character map and font viewer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		UCD>=0:textproc/UCD \
		${LOCALBASE}/share/aclocal/yelp.m4:textproc/yelp-tools \
		vala>=0.16:lang/vala
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpcre2-8.so:devel/pcre2

USES=		desktop-file-utils gettext-tools gnome localbase meson perl5 pkgconfig \
		python:build tar:xz
USE_GNOME=	cairo glib20 gtk30 introspection:build
USE_PERL5=	build
BINARY_ALIAS=	python3=${PYTHON_CMD}
USE_LDCONFIG=	yes
MESON_ARGS=	-Ducd_path=${LOCALBASE}/share/unicode/ucd/

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	3efb47b75b61d7c6db7e48d72f7aa8c4d4365011

GLIB_SCHEMAS=	org.gnome.Charmap.gschema.xml

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

.include <bsd.port.mk>
