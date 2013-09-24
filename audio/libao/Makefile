# Created by: t.vanklaveren@student.utwente.nl
# $FreeBSD$

PORTNAME=	libao
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/ao/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Portable audio output library

USES=		pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-arts

OPTIONS_DEFINE=	DOCS ESOUND NAS PULSEAUDIO
OPTIONS_SUB=	yes

NAS_LIB_DEPENDS=libaudio.so:${PORTSDIR}/audio/nas
NAS_CONFIGURE_ENABLE=	nas

PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse

ESOUND_CONFIGURE_ENABLE=esd
.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/libao.conf|${PREFIX}&|' \
		${WRKSRC}/libao.conf.5 ${WRKSRC}/include/ao/ao_private.h \
		${WRKSRC}/doc/config.html

.include <bsd.port.mk>
