# New ports collection makefile for:	freeciv
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $FreeBSD$
#

PORTNAME=	freeciv
PORTVERSION=	2.0.8
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/pub/freeciv/stable/ \
		ftp://ftp.netc.pt/pub/freeciv/stable/ \
		ftp://ftp.pvv.ntnu.no/pub/freeciv/stable/

MAINTAINER?=	infofarmer@FreeBSD.org
COMMENT?=	A civilisation clone for X11; multiplayer

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png

USE_GETTEXT=	yes
USE_XPM=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN6=		civserver.6 civclient.6

.include <bsd.port.pre.mk>

.if 	!defined(WITH_GTK) && !defined(WITH_GTK12) && !defined(WITH_GTK2) && \
	!defined(WITHOUT_GNOME)
AUTO_DEPENDS=	yes
.if ${HAVE_GNOME:Mgtk20}!=""
WITH_GTK2=	yes
.elif ${HAVE_GNOME:Mgtk12}!=""
WITH_GTK=	yes
.endif
.endif

.if defined(WITH_GTK2)
CONFLICTS=	freeciv-1* freeciv-gtk-1*
USE_GNOME+=	gtk20
PKGNAMESUFFIX?=	-gtk2
CONFIGURE_ARGS+=	--enable-client=gtk2
PLIST_FILES+=	%%DATADIR%%/freeciv.rc-2.0
.elif defined(WITH_GTK) || defined(WITH_GTK12)
CONFLICTS=	freeciv-1* freeciv-gtk2-1*
USE_GNOME+=	imlib gtk12
PKGNAMESUFFIX?=	-gtk
CONFIGURE_ARGS+=	--enable-client=gtk
PLIST_FILES+=	%%DATADIR%%/freeciv.rc
.else
CONFLICTS=	freeciv-gtk-1* freeciv-gtk2-1*
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
CONFIGURE_ARGS+=	--enable-client=xaw3d
PLIST_FILES+=	%%DATADIR%%/Freeciv
.endif

pre-fetch:
.if defined(AUTO_DEPENDS)
	@${ECHO} -n "No WITH_GTK, WITH_GTK2 or WITHOUT_GNOME defined, autodetecting: "
.if defined(WITH_GTK)
	@${ECHO} "GTK"
.elif defined(WITH_GTK2)
	@${ECHO} "GTK2"
.else
	@${ECHO} "Xaw3d"
.endif
.endif

post-patch:
	cd ${WRKSRC}; ${FIND} . -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} -e 's/@program_transform_name@//'

.include <bsd.port.post.mk>
