# Created by: Romain Tartière <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	paprefs
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/${PORTNAME}/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	GTK configuration dialog for PulseAudio

LIB_DEPENDS=	libglademm-2.4.so:${PORTSDIR}/devel/libglademm24 \
		libgconfmm-2.6.so:${PORTSDIR}/devel/gconfmm26 \
		libpulse.so:${PORTSDIR}/audio/pulseaudio

GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig
NO_STAGE=	yes
USE_GNOME=	gnomeprefix intltool

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
