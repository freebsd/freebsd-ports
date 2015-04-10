# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	wavbreaker
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tool to split and merge wav files

LICENSE=	GPLv2 # or any later version

OPTIONS_DEFINE=	PULSEAUDIO NLS
OPTIONS_SUB=	yes

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=pulse
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

USE_GNOME=	gtk20 libxml2
USES=		gmake pathfix pkgconfig desktop-file-utils
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-alsa
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
