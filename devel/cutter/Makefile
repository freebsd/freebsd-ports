# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cutter
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Unit Testing Framework for C and C++

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libpangocairo-1.0.so:${PORTSDIR}/x11-toolkits/pango

CPPFLAGS+=	"-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--disable-gtk-doc-html --with-html-dir=${PREFIX}/share/doc
GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pkgconfig
USE_GNOME=	intltool gnomehack glib20 gtk20
USE_LDCONFIG=	yes
WANT_GSTREAMER=	yes

OPTIONS_DEFINE=	GOFFICE GSTREAMER SOUP LCOV
GOFFICE_DESC=	GOffice support
SOUP_DESC=	libsoup support
LCOV_DESC=	Force dependency on lcov

regression-test: build
	@${SETENV} LC_ALL=C ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} check

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGOFFICE}
CONFIGURE_ARGS+=--enable-goffice
# the 0.8 is part of the library name don't remove it.
LIB_DEPENDS+=	libgoffice-0.8.so:${PORTSDIR}/devel/goffice
PLIST_SUB+=	GOFFICE=""
.else
CONFIGURE_ARGS+=--disable-goffice
PLIST_SUB+=	GOFFICE="@comment "
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
CONFIGURE_ARGS+=--enable-gstreamer
USE_GSTREAMER=yes
PLIST_SUB+=	GST="" GST_VERSION="${GST_VERSION}"
.else
CONFIGURE_ARGS+=--disable-gstreamer
PLIST_SUB+=	GST="@comment "
.endif

.if ${PORT_OPTIONS:MLCOV}
RUN_DEPENDS+=	lcov:${PORTSDIR}/devel/lcov
.endif

.if ${PORT_OPTIONS:MSOUP}
CONFIGURE_ARGS+=--enable-libsoup
LIB_DEPENDS+=	libsoup-2.so:${PORTSDIR}/devel/libsoup
PLIST_SUB+=	SOUP=""
.else
CONFIGURE_ARGS+=--disable-libsoup
PLIST_SUB+=	SOUP="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
