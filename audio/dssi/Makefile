# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	dssi
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for audio processing plugins

LICENSE=	BSD LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo:${PORTSDIR}/audio/liblo \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		jack.0:${PORTSDIR}/audio/jack
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

OPTIONS_DEFINE=	QT4

USES=	pathfix pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		dssi_analyse_plugin.1 dssi_list_plugins.1 dssi_osc_send.1 \
		dssi_osc_update.1 jack-dssi-host.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	corelib gui
QT_NONSTANDARD=	yes
PLIST_SUB=	QT=""
.else
PLIST_SUB=	QT="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^lts_uidir/s|^|@HAVE_QT_TRUE@| ; \
		 /^trivial_sampler_uidir/s|^|@HAVE_QT_TRUE@| ; \
		 s|-ldl$$||' ${WRKSRC}/examples/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-ldl$$||' ${WRKSRC}/jack-dssi-host/Makefile.in
	@${REINPLACE_CMD} -e \
		'/alsa >=/s|$$PKG_CONFIG|${FALSE}|' ${WRKSRC}/configure
.if empty(PORT_OPTIONS:MQT4)
	@${REINPLACE_CMD} -e \
		'/QtCore >=/s|$$PKG_CONFIG|${FALSE}|' ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
