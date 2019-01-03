# $FreeBSD$

PORTNAME=	sequeler
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.7
CATEGORIES=	databases

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Friendly SQL client

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vala:lang/vala
LIB_DEPENDS=	libfixposix.so:devel/libfixposix \
		libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libsecret-1.so:security/libsecret \
		libssh2.so:security/libssh2

USES=		desktop-file-utils gettext gnome meson pkgconfig python:3.5+,build
USE_GITHUB=	yes
GH_ACCOUNT=	Alecaddd
USE_GNOME=	cairo glib20 gtk30 gtksourceview3 libgda5
GLIB_SCHEMAS=	com.github.alecaddd.sequeler.gschema.xml
INSTALLS_ICONS=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD} # for meson/post_install.py

.include <bsd.port.mk>
