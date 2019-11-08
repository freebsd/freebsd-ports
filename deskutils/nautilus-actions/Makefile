# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nautilus-actions
PORTVERSION=	3.2.4
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extension for Nautilus to configure programs to launch on files

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libdbus-glib-1.so:devel/dbus-glib \
		libgtop-2.0.so:devel/libgtop \
		libunique-3.0.so:x11-toolkits/libunique3

USES=		gettext gmake gnome libtool pkgconfig tar:xz
USE_GNOME=	gtk30 intltool nautilus3
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-nautilus-extdir=${LOCALBASE}/lib/nautilus/extensions-3.0 \
		--with-default-io-provider=na-desktop \
		--with-gtk=3 \
		--disable-gconf
INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS ChangeLog ChangeLog-2008 ChangeLog-2009 ChangeLog-2010 \
		ChangeLog-2011 ChangeLog-2012 COPYING COPYING-DOCS INSTALL \
		MAINTAINERS NEWS README README-GCONF TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror"|"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|doc/@PACKAGE@-@VERSION@|doc/@PACKAGE@|g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/docs/Makefile.in

.include <bsd.port.mk>
