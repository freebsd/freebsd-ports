# Created by: Liam J. Foy <liamfoy@sepulcrum.org>
# $FreeBSD$

PORTNAME=	gtick
PORTVERSION=	0.5.2
CATEGORIES=	audio
MASTER_SITES=	http://www.antcom.de/gtick/download/ CENKES

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A metronome application

LICENSE=	GPLv3

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libpulse-simple.so:${PORTSDIR}/audio/pulseaudio

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
