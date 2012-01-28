# New ports collection makefile for:	dssi
# Date created:		2007-01-12
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	dssi
PORTVERSION=	1.1.1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for audio processing plugins

LICENSE=	BSD LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo.7:${PORTSDIR}/audio/liblo \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		jack.0:${PORTSDIR}/audio/jack
RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

OPTIONS=	QT "Enable Qt4 support" off

USE_GNOME=	gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		dssi_analyse_plugin.1 dssi_list_plugins.1 dssi_osc_send.1 \
		dssi_osc_update.1 jack-dssi-host.1

.include <bsd.port.options.mk>

.if defined(WITH_QT)
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui
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
.if !defined(WITH_QT)
	@${REINPLACE_CMD} -e \
		'/QtCore >=/s|$$PKG_CONFIG|${FALSE}|' ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
