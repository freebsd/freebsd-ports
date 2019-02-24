# Created by: kipz <somicide@gmail.com>
# $FreeBSD$

PORTNAME=	gitg
PORTVERSION=	3.30.1
PORTREVISION=	1
CATEGORIES=	devel deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GTK-based git repository viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		valac:lang/vala
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libenchant.so:textproc/enchant \
		libgee-0.8.so:devel/libgee \
		libgit2.so:devel/libgit2 \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libpeas-1.0.so:devel/libpeas \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libsecret-1.so:security/libsecret
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

CONFLICTS=	gitg0-[0-9]*
PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gnome localbase \
		meson pathfix pkgconfig python:3.4+,build tar:xz
USE_GNOME=	cairo gtk30 gtksourceview3 intltool introspection

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GLIB_SCHEMAS=	org.gnome.gitg.gschema.xml
BINARY_ALIAS=	python3=${PYTHON_VERSION}

OPTIONS_DEFINE=	PYTHON
OPTIONS_SUB=	yes

PYTHON_USES=	python:3.2+
PYTHON_MESON_TRUE=	python
PYTHON_USE=	GNOME=pygobject3

post-patch:
	@${REINPLACE_CMD} -e 's|0.27.0|0.28.0|g' \
		${WRKSRC}/meson.build

post-install-PYTHON-on:
	(cd ${STAGEDIR}${PREFIX} \
		&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
