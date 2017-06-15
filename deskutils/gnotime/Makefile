# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	gnotime
PORTVERSION=	2.4.1
PORTREVISION=	5
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/gttr/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time tracker for gnome2

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqof.so:databases/qof

USES=		gettext gmake libtool pathfix pkgconfig
USE_XORG=	xscrnsaver
USE_GNOME=	gnomeprefix gtkhtml3 intlhack libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GUILE_CFLAGS="$$(guile-config compile)" \
		GUILE_LIBS="$$(guile-config link)"
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnotime.schemas

OPTIONS_SINGLE= GV
OPTIONS_SINGLE_GV=	GUILE1 GUILE2
OPTIONS_DEFAULT=	GUILE1

GUILE1_DESC=	Use lang/guile
GUILE2_DESC=	Use lang/guile2

GUILE1_LIB_DEPENDS=	libguile.so:lang/guile
GUILE2_LIB_DEPENDS=	libguile-2.0.so:lang/guile2
GUILE2_LDFLAGS=		-lm

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install-data-am/s|install-data-local||' \
		${WRKSRC}/gconf/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^AM_CFLAGS =/s|-g||' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
