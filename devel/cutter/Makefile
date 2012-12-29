# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cutter
PORTVERSION=	1.2.2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Unit Testing Framework for C and C++

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		pangocairo:${PORTSDIR}/x11-toolkits/pango

CPPFLAGS+=	"-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--disable-gtk-doc-html --with-html-dir=${PREFIX}/share/doc
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool gnomehack glib20 gtk20
USE_LDCONFIG=	yes
WANT_GSTREAMER=	yes

MANLANG=	"" ja
MAN1=		cut-diff.1 cutter.1

OPTIONS_DEFINE=	GOFFICE GSTREAMER SOUP LCOV
GOFFICE_DESC=	GOffice support
SOUP_DESC=	libsoup support
LCOV_DESC=	Force dependency on lcov

regression-test: build
	@${SETENV} LC_ALL=C ${GMAKE} -C ${WRKSRC} check

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGOFFICE}
CONFIGURE_ARGS+=--enable-goffice
LIB_DEPENDS+=	goffice-0.6:${PORTSDIR}/devel/goffice06
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
LIB_DEPENDS+=	soup-2:${PORTSDIR}/devel/libsoup
PLIST_SUB+=	SOUP=""
.else
CONFIGURE_ARGS+=--disable-libsoup
PLIST_SUB+=	SOUP="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
