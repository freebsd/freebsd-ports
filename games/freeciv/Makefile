# New ports collection makefile for:	freeciv
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $FreeBSD$
#

PORTNAME=	freeciv
PORTVERSION=	2.0.8
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/pub/freeciv/stable/ SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Free turn-based multiplayer strategy

USE_GCC=	3.4+
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN6=		civserver.6 civclient.6

.ifndef WITHOUT_X11
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png
USE_XPM=	yes
WANT_GNOME=	yes
CONFIGURE_ENV+=	SDL_CONFIG="${SDL_CONFIG}"
PLIST_SUB+=	X11=""
.endif

.include <bsd.port.pre.mk>

.if 	!defined(WITH_GTK) && !defined(WITH_GTK12) && !defined(WITH_GTK2) && \
	!defined(WITHOUT_GNOME) && !defined(WITHOUT_X11)
AUTO_DEPENDS=	yes
.if ${HAVE_GNOME:Mgtk20}!=""
WITH_GTK2=	yes
.elif ${HAVE_GNOME:Mgtk12}!=""
WITH_GTK=	yes
.endif
.endif

CFG_PATCH=s/[[:<:]](test)[[:space:]]*([^=]*)[[:>:]][[:space:]]*==[[:space:]]*([^()|&;<>]*)[[:>:]]/\1 "\2" = "\3"/g;
CONFLICTS_ALL=	freeciv freeciv-gtk freeciv-gtk2 freeciv-nox11
CONFLICTS=	${CONFLICTS_ALL:S/^${PKGBASE}$//:S/$/-[0-9]*/}

.if defined(WITHOUT_X11)
PLIST_SUB+=	X11="@comment "
PKGNAMESUFFIX?=	-nox11
CONFIGURE_ARGS+=	--enable-client=no
.elif defined(WITH_GTK2)
USE_GNOME+=	gtk20
PKGNAMESUFFIX?=	-gtk2
CONFIGURE_ARGS+=	--enable-client=gtk2
PLIST_FILES+=	%%DATADIR%%/freeciv.rc-2.0
.elif defined(WITH_GTK) || defined(WITH_GTK12)
USE_GNOME+=	imlib gtk12
PKGNAMESUFFIX?=	-gtk
CONFIGURE_ARGS+=	--enable-client=gtk
PLIST_FILES+=	%%DATADIR%%/freeciv.rc
.else
LIB_DEPENDS+=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d
CONFIGURE_ARGS+=	--enable-client=xaw3d
PLIST_FILES+=	%%DATADIR%%/Freeciv
.endif

pre-fetch:
.ifdef AUTO_DEPENDS
	@${ECHO} -n "No WITH_GTK, WITH_GTK2, WITHOUT_GNOME or WITHOUT_X11 defined, autodetecting: "
.ifdef WITHOUT_X11
	@${ECHO} "NOX11"
.elifdef WITH_GTK2
	@${ECHO} "GTK2"
.elifdef WITH_GTK
	@${ECHO} "GTK"
.else
	@${ECHO} "Xaw3d"
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -Ee '${CFG_PATCH}' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} -e 's/@program_transform_name@//'

.if ${OSVERSION} < 500000
BROKEN=	Does not build on 4.x
.endif

.include <bsd.port.post.mk>
