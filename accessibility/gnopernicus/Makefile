# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/accessibility/gnopernicus/Makefile,v 1.85 2007/07/23 19:03:49 mezz Exp $

PORTNAME=	gnopernicus
PORTVERSION=	1.1.2
PORTREVISION=	11
CATEGORIES=	accessibility x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of accessibility apps for GNOME 2

LIB_DEPENDS=	libgnome-mag.so:${PORTSDIR}/accessibility/gnome-mag

USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_XORG=	x11
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack libgnomeui atspi gnomespeech
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	X_LIBS=-lX11
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	SED="${SED}"
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	brlmonitor.schemas gnopernicus.schemas remote.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|^F||' \
		${WRKSRC}/help/braille_monitor/C/brlmonitor-C.omf \
		${WRKSRC}/help/braille_monitor/es/brlmonitor-es.omf
	@${CP} ${FILESDIR}/gnopernicus-mag-config ${WRKSRC}/gnopi
	@${REINPLACE_CMD} -e 's|test$$||' ${WRKSRC}/*/Makefile.in

.include <bsd.port.mk>
