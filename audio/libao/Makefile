# Created by: t.vanklaveren@student.utwente.nl
# $FreeBSD$

PORTNAME=	libao
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/ao/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Portable audio output library

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--disable-arts
INSTALL_TARGET=	install-strip

# do not install
MAKE_ARGS=	ckport_DATA=""

OPTIONS_DEFINE=	DOCS ESOUND NAS PULSEAUDIO
OPTIONS_SUB=	yes

NAS_LIB_DEPENDS=libaudio.so:audio/nas
NAS_CONFIGURE_ENABLE=	nas

PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse

ESOUND_CONFIGURE_ENABLE=esd
ESOUND_USE=	GNOME=esound

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/libao.conf|${PREFIX}&|' \
		${WRKSRC}/libao.conf.5 ${WRKSRC}/include/ao/ao_private.h \
		${WRKSRC}/doc/config.html

.include <bsd.port.mk>
