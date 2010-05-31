# New ports collection makefile for:	XaoS
# Date created:				24 February 1996
# Whom:					Joseph Koshy <koshy@india.hp.com>
#
# $FreeBSD$
#

PORTNAME=	xaos
PORTVERSION=	3.5
PORTREVISION=	2
CATEGORIES=	graphics math
MASTER_SITES=	SF/${PORTNAME}/XaoS/${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A real-time fractal browser for X11 and ASCII terminals

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

OPTIONS=	PTHREAD "Enable SMP support (experimental)" off \
		GTK2 "GTK+ User Interface (experimental)" off \
		NLS "Native Language Support" on

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-aa-driver=no --with-dga-driver=no \
		--with-ggi-driver=no --with-svga-driver=no \
		--with-sffe=no

MAN6=		xaos.6
INFO=		xaos

PLIST_SUB+=	XAOSDIR="share/XaoS"

DESKTOP_ENTRIES=	"XaoS" "Fractal zoomer" "" "xaos" "" false

.include <bsd.port.options.mk>

.if defined(WITH_PTHREAD)
CONFIGURE_ARGS+=	--with-pthread=yes
CONFIGURE_ENV+=		LIBS="${PTHREAD_LIBS}" \
			CFLAGS="${PTHREAD_CFLAGS} ${CFLAGS}"
.else
CONFIGURE_ARGS+=	--with-pthread=no
.endif

.if defined(WITH_GTK2)
USE_GNOME=	gtk20
CONFIGURE_ARGS+=	--with-gtk-driver=yes --with-x11-driver=no
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,/usr\(/share/locale\),${PREFIX}\1,g' \
		${WRKSRC}/configure \
		${WRKSRC}/src/ui/ui.c

.include <bsd.port.mk>
