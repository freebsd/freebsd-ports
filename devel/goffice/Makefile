PORTNAME=	goffice
PORTVERSION=	0.10.61
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GTK set of document centric objects and utilities
WWW=		https://gitlab.gnome.org/GNOME/goffice

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libspectre.so:print/libspectre

USES=		gettext-tools gmake gnome libtool pathfix perl5 pkgconfig \
		shebangfix tar:xz xorg
USE_GNOME=	cairo gtk30 intltool:build introspection:build libgsf \
		librsvg2 libxslt
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	xrender xext
SHEBANG_FILES=	${WRKSRC}/tools/introspection-identifier-filter

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lasem=no --with-config-backend=gsettings \
		--enable-introspection

INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=${PORTVERSION} SHORT_VER=${PORTVERSION:R} LIB_VER=${PORTVERSION:E}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/goffice/${SHORT_VER}/plugins

.include <bsd.port.mk>
