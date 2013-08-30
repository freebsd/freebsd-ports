# Created by: Liam J. Foy <liamfoy@sepulcrum.org>
# $FreeBSD$

PORTNAME=	gtick
PORTVERSION=	0.5.2
CATEGORIES=	audio
MASTER_SITES=	http://www.antcom.de/gtick/download/ CENKES

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A metronome application

LICENSE=	GPLv3

LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile \
		pulse-simple:${PORTSDIR}/audio/pulseaudio

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=	gtick.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
