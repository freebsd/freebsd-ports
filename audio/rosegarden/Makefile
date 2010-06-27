# New ports collection makefile for:	rosegarden
# Date created:		04 Aug 1996
# Whom:			shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	rosegarden
PORTVERSION=	10.04.2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/10.04/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Rosegarden Editor and Sequencer suite

BUILD_DEPENDS=	${LOCALBASE}/lib/tclmidi/tclmidi31.so:${PORTSDIR}/audio/tclmidi \
		dssi_osc_update:${PORTSDIR}/audio/dssi \
		makedepend:${PORTSDIR}/devel/makedepend
RUN_DEPENDS=	${LOCALBASE}/lib/tclmidi/tclmidi31.so:${PORTSDIR}/audio/tclmidi \
		dssi_osc_update:${PORTSDIR}/audio/dssi
LIB_DEPENDS+=	lrdf.2:${PORTSDIR}/textproc/liblrdf \
		fftw3.5:${PORTSDIR}/math/fftw3 \
		fftw3f.5:${PORTSDIR}/math/fftw3-float \
		asound.2:${PORTSDIR}/audio/alsa-lib

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml network corelib sql qt3support \
		rcc_build moc_build uic_build linguist_build
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	QTLIBDIR=${QT_LIBDIR} LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
