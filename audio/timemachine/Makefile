# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	timemachine
PORTVERSION=	0.3.3
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/timemachine/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JACK audio capture tool

LICENSE=	GPLv2

LIB_DEPENDS=	jack:${PORTSDIR}/audio/jack \
		lo:${PORTSDIR}/audio/liblo \
		sndfile:${PORTSDIR}/audio/libsndfile

OPTIONS_DEFINE=	LASH

USES=		gmake pathfix pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
LDFLAGS+=	-lm

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLASH}
LIB_DEPENDS+=	lash:${PORTSDIR}/audio/lash
.else
CONFIGURE_ARGS+=--disable-lash
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^PACKAGE_CFLAGS=/s|-g||; \
		 /^PACKAGE_LIBS=/s|-g||' ${WRKSRC}/configure

.include <bsd.port.mk>
