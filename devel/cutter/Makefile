# New ports collection makefile for:	cutter
# Date created:		2010-01-10
# Whom:			Romain Tartiere <romain@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cutter
PORTVERSION=	1.1.9
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

OPTIONS=	GOFFICE "Enable GOffice support"   yes \
		GST     "Enable GStreamer support" yes \
		SOUP    "Enable libsoup support"   yes \
		LCOV    "Force dependency on lcov" no

regression-test: build
	@${SETENV} LC_ALL=C ${GMAKE} -C ${WRKSRC} check

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.options.mk>

.if defined(WITHOUT_GOFFICE)
CONFIGURE_ARGS+=--disable-goffice
PLIST_SUB+=	GOFFICE="@comment "
.else
CONFIGURE_ARGS+=--enable-goffice
LIB_DEPENDS+=	goffice-0.6:${PORTSDIR}/devel/goffice06
PLIST_SUB+=	GOFFICE=""
.endif

.if defined(WITHOUT_GST)
CONFIGURE_ARGS+=--disable-gstreamer
PLIST_SUB+=	GST="@comment "
.else
CONFIGURE_ARGS+=--enable-gstreamer
USE_GSTREAMER=yes
PLIST_SUB+=	GST="" GST_VERSION="${GST_VERSION}"
.endif

.if defined(WITH_LCOV)
RUN_DEPENDS+=	lcov:${PORTSDIR}/devel/lcov
.endif

.if defined(WITHOUT_SOUP)
CONFIGURE_ARGS+=--disable-libsoup
PLIST_SUB+=	SOUP="@comment "
.else
CONFIGURE_ARGS+=--enable-libsoup
LIB_DEPENDS+=	soup-2:${PORTSDIR}/devel/libsoup
PLIST_SUB+=	SOUP=""
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
