PORTNAME=	sequeler
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
PORTREVISION=	5
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Friendly SQL client
WWW=		https://github.com/Alecaddd/sequeler

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libsecret-1.so:security/libsecret \
		libssh2.so:security/libssh2

USES=		desktop-file-utils gettext gnome meson pkgconfig \
		python:build vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	Alecaddd
USE_GNOME=	cairo glib20 gtk30 gtksourceview3 libgda5
GLIB_SCHEMAS=	com.github.alecaddd.sequeler.gschema.xml

# for build-aux/meson_post_install.py
BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
