# New ports collection makefile for:	libvisual-plugins
# Date created:		12 February 2005
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libvisual-plugins
PORTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/libvisual/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of plugins for the libvisual framework

LIB_DEPENDS=	visual.0:${PORTSDIR}/graphics/libvisual

WANT_GNOME=	yes
USE_GNOME=	gnometarget pkgconfig
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700029
BROKEN=		Broken objformat handling
.endif

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake

.if defined(WITH_MPLAYER)
BUILD_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
CONFIGURE_ARGS+=	--enable-mplayer
PLIST_SUB+=	MPLAYER=""
.else
CONFIGURE_ARGS+=	--disable-mplayer
PLIST_SUB+=	MPLAYER="@comment "
.endif

.if exists(${LOCALBASE}/lib/libgoom2.a) || defined(WITH_GOOM)
LIB_DEPENDS+=	goom2.0:${PORTSDIR}/graphics/goom
PLIST_SUB+=	GOOM=""
.else
PLIST_SUB+=	GOOM="@comment "
.endif

.if ${HAVE_GNOME:Mgtk20}!="" || defined(WITH_GTK20)
USE_GNOME+=	gtk20
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

.if (${HAVE_GNOME:Mesound}!="" || defined(WITH_ESOUND)) && !defined(WITHOUT_ESOUND)
USE_GNOME+=	esound
PLIST_SUB+=	ESOUND=""
.else
PLIST_SUB+=	ESOUND="@comment "
.endif

.if defined(WITH_JACK) || exists(${LOCALBASE}/lib/libjack.a)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
PLIST_SUB+=	JACK=""
.else
PLIST_SUB+=	JACK="@comment "
.endif

pre-everyting::
	@${ECHO_CMD} ""
.if !defined(WITH_MPLAYER)
	@${ECHO_CMD} "Enable the mplayer input plugin by defining WITH_MPLAYER=yes."
.endif
.if !defined(WITH_JACK)
	@${ECHO_CMD} "Enable the Jack input plugin by defining WITH_JACK=yes."
.endif
.if !defined(WITH_GOOM)
	@${ECHO_CMD} "Enable the Goom visualisation plugin by defining WITH_GOOM=yes."
.endif
.if !defined(WITH_GTK20)
	@${ECHO_CMD} "Enable the Goom visualisation plugin by defining WITH_GOOM=yes."
.endif
.if !defined(WITH_ESOUND)
	@${ECHO_CMD} "Enable the Goom visualisation plugin by defining WITH_GOOM=yes."
.endif
	@${ECHO_CMD} ""

.include <bsd.port.post.mk>
