PORTNAME=	gedit-plugins
DISTVERSION=	48.2
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for gedit
WWW=		https://gitlab.gnome.org/World/gedit/gedit-plugins

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^48\.

BUILD_DEPENDS=	gedit=48.2:editors/gedit \
		itstool:textproc/itstool
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas1 \
		libgedit-tepl-6.so:x11-toolkits/tepl6 \
		libgedit-gtksourceview-300.so:x11-toolkits/libgedit-gtksourceview
RUN_DEPENDS=	gedit=48.2:editors/gedit

USES=		compiler:c11 gettext gnome localbase meson pkgconfig \
		tar:bz2
USE_GNOME=	glib20 gtk30
USE_CSTD=	c11
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/gedit

GLIB_SCHEMAS=	org.gnome.gedit.plugins.drawspaces.gschema.xml \
		org.gnome.gedit.plugins.wordcompletion.gschema.xml

.include <bsd.port.mk>
