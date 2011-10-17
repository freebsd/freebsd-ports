# New ports collection makefile for:	rosegarden
# Date created:		04 Aug 1996
# Whom:			shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	rosegarden
PORTVERSION=	11.06
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	The Rosegarden Editor and Sequencer suite

LICENSE=	GPLv2

BUILD_DEPENDS=	dssi_osc_update:${PORTSDIR}/audio/dssi \
		makedepend:${PORTSDIR}/devel/makedepend
RUN_DEPENDS=	dssi_osc_update:${PORTSDIR}/audio/dssi \
		lilypond:${PORTSDIR}/print/lilypond
LIB_DEPENDS+=	lrdf.2:${PORTSDIR}/textproc/liblrdf \
		fftw3:${PORTSDIR}/math/fftw3 \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		asound.2:${PORTSDIR}/audio/alsa-lib \
		lirc_client:${PORTSDIR}/comms/lirc

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml network corelib sql qt3support \
		rcc_build moc_build uic_build linguist_build
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	QTLIBDIR=${QT_LIBDIR}
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
