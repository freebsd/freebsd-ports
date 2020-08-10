# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	akira
PORTVERSION=	0.0.11
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical UI/UX design tool

LICENSE=	GPLv3+

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgoocanvas-2.0.so:graphics/goocanvas2 \
		libgranite.so:x11-toolkits/granite \
		libjson-glib-1.0.so:devel/json-glib

USES=		desktop-file-utils gettext gnome libarchive meson pkgconfig \
		python:build shared-mime-info shebangfix
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_GITHUB=	yes
GH_ACCOUNT=	akiraux
GH_PROJECT=	Akira
GLIB_SCHEMAS=	com.github.akiraux.akira.gschema.xml
INSTALLS_ICONS=	yes
SHEBANG_FILES=	build-aux/meson/post_install.py

post-patch:
# XXX: workaround for segfault in gtk_application_set_accels_for_action(),
# see https://github.com/akiraux/Akira/issues/392 and also potentially
# related https://gitlab.gnome.org/GNOME/vala/-/issues/626 bug reports.
	@${REINPLACE_CMD} -e 's,[^ ]*\.to_array (),{ &[0] },' \
		${WRKSRC}/src/Services/ActionManager.vala

post-install:
	${LN} -sf com.github.akiraux.akira ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
