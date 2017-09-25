# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	orage
PORTVERSION=	4.12.1
PORTREVISION=	3
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Calendar application for the Xfce Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt \
	libdbus-glib-1.so:devel/dbus-glib \
	libical.so:devel/libical

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		pkgconfig libtool gettext desktop-file-utils gmake \
	xfce tar:bzip2
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	panel

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=	NOTIFY
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	libnotify

CFLAGS+=	-I${LOCALBASE}/include/libical

CONFIGURE_ARGS=	--enable-dbus

post-patch:
	@${REINPLACE_CMD} -e 's|(datadir)/orage/doc/C|(datadir)/doc/orage/C|' \
		${WRKSRC}/doc/C/Makefile.in \
		${WRKSRC}/doc/C/images/Makefile.in

.include <bsd.port.mk>
