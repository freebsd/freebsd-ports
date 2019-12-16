# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	goffice
PORTVERSION=	0.10.46
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GTK+ set of document centric objects and utilities

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libspectre.so:print/libspectre \
		libfribidi.so:converters/fribidi

USES=		gettext gmake gnome libtool pathfix perl5 pkgconfig \
		shebangfix tar:xz xorg
USE_GNOME=	cairo gtk30 intlhack introspection:build libgsf librsvg2 libxslt
USE_XORG=	xrender xext
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-lasem=no --with-config-backend=gsettings \
		--enable-compile-warnings=no \
		--enable-introspection
USE_PERL5=	build
SHEBANG_FILES=	${WRKSRC}/tools/introspection-identifier-filter

PLIST_SUB=	VERSION=${PORTVERSION} SHORT_VER=${PORTVERSION:R}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/goffice/${SHORT_VER}/plugins
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgoffice-0.10.so.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/goffice/${PORTVERSION}/plugins/*/*.so

.include <bsd.port.mk>
