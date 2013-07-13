# Created by: shanee@augusta.de
# $FreeBSD$

PORTNAME=	rosegarden
PORTVERSION=	13.04
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	General purpose music editor and sequencer suite

LICENSE=	GPLv2

BUILD_DEPENDS=	dssi_osc_update:${PORTSDIR}/audio/dssi \
		makedepend:${PORTSDIR}/devel/makedepend
LIB_DEPENDS=	asound:${PORTSDIR}/audio/alsa-lib \
		lirc_client:${PORTSDIR}/comms/lirc \
		fftw3:${PORTSDIR}/math/fftw3 \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		lrdf:${PORTSDIR}/textproc/liblrdf
RUN_DEPENDS=	dssi_osc_update:${PORTSDIR}/audio/dssi \
		lilypond:${PORTSDIR}/print/lilypond

USES=		gmake pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	QTLIBDIR=${QT_LIBDIR}
USE_QT4=	gui network xml rcc_build moc_build uic_build linguist_build
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
