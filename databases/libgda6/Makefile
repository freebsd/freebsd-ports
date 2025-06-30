PORTNAME=	libgda
DISTVERSION=	6.0.1.g${SNAPDATE}
PORTREVISION=	1
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	6
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Database access library
WWW=		https://gitlab.gnome.org/GNOME/libgda

LICENSE=	LGPL20+

BUILD_DEPENDS=	iso-codes>0:misc/iso-codes
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libgcrypt.so:security/libgcrypt \
		libsecret-1.so:security/libsecret

USES=		cpe gettext meson gnome pkgconfig python:build shebangfix \
		sqlite ssl tar:bz2 vala:build
CPE_VENDOR=	gnome
USE_GNOME=	glib20 gtk30 intltool:build introspection:build libxml2 \
		libxslt
SHEBANG_FILES=	providers/raw_spec.py
# Or use patch from https://gitlab.gnome.org/GNOME/libgda/-/merge_requests/208
CFLAGS=		-Wno-deprecated-non-prototype

MESON_ARGS=	-Dui=false \
		-Dhelp=false \
		-Dsqlcipher=false \
		-Dlibsoup=false \
		-Dlibsecret=true \
		-Dpostgres=false \
		-Dmysql=false

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_TAGNAME=	c149606b
SNAPDATE=	20250302

.include <bsd.port.mk>
