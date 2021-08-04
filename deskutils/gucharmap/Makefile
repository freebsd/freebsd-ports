# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	gucharmap
PORTVERSION=	13.0.8
CATEGORIES=	deskutils gnome
#MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Unicode/ISO10646 character map and font viewer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		UCD>=0:textproc/UCD \
		${LOCALBASE}/share/aclocal/yelp.m4:textproc/yelp-tools \
		vala>=0.16:lang/vala
LIB_DEPENDS=	libfreetype.so:print/freetype2

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
GL_COMMIT=	cdbc989f552833ea4ac0f8fefd095ebf6d61333e

GLIB_SCHEMAS=	org.gnome.Charmap.gschema.xml

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

.include <bsd.port.mk>
