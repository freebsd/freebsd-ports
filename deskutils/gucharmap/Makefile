PORTNAME=	gucharmap
PORTVERSION=	17.0.0 # must sync with textproc/UCD
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Unicode/ISO10646 character map and font viewer
WWW=		https://gitlab.gnome.org/GNOME/gucharmap

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		UCD=17.0.0,1:textproc/UCD
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpcre2-8.so:devel/pcre2

USES=		desktop-file-utils gettext-tools gnome localbase meson perl5 pkgconfig \
		python:build tar:bz2 vala:build
USE_GNOME=	atk cairo glib20 gtk30 introspection:build
USE_PERL5=	build
BINARY_ALIAS=	python3=${PYTHON_CMD}
USE_LDCONFIG=	yes
MESON_ARGS=	-Ducd_path=${LOCALBASE}/share/unicode/ucd/

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME

GLIB_SCHEMAS=	org.gnome.Charmap.gschema.xml

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

.include <bsd.port.mk>
