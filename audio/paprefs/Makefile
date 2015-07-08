# Created by: Romain Tartière <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	paprefs
PORTVERSION=	0.9.10
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK configuration dialog for PulseAudio

LIB_DEPENDS=	libglademm-2.4.so:${PORTSDIR}/devel/libglademm24 \
		libpulse.so:${PORTSDIR}/audio/pulseaudio

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gmake pkgconfig
USE_GNOME=	gconfmm26 gnomeprefix

CONFIGURE_ARGS=	--disable-lynx

OPTIONS_DEFINE=	PK NLS
PK_DESC=	Force dependency on PackageKit

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPK}
LIB_DEPENDS+=	libpackagekit-glib2.so:${PORTSDIR}/ports-mgmt/packagekit
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
