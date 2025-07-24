PORTNAME=	gitg
DISTVERSION=	44
CATEGORIES=	devel deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK-based git repository viewer
WWW=		https://wiki.gnome.org/Apps/Gitg

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libenchant.so:textproc/enchant \
		libgee-0.8.so:devel/libgee \
		libgit2.so:devel/libgit2 \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libjson-glib-1.0.so:devel/json-glib \
		libpeas-1.0.so:devel/libpeas1 \
		libgspell-1.so:textproc/gspell \
		libdazzle-1.0.so:x11-toolkits/libdazzle \
		libsecret-1.so:security/libsecret
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gnome localbase \
		meson pkgconfig python:build tar:xz vala:build
USE_GNOME=	cairo gdkpixbuf gtk30 gtksourceview4 intltool introspection

USE_LDCONFIG=	yes
GLIB_SCHEMAS=	org.gnome.gitg.gschema.xml
BINARY_ALIAS=	python3=${PYTHON_VERSION}

OPTIONS_DEFINE=	PYTHON
OPTIONS_SUB=	yes

PYTHON_USES=	python
PYTHON_MESON_TRUE=	python
PYTHON_USE=	GNOME=pygobject3

post-install-PYTHON-on:
	(cd ${STAGEDIR}${PREFIX} \
		&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
