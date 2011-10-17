# New ports collection makefile for:	fmit
# Date created:		2007-09-08
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fmit
PORTVERSION=	0.99.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.gna.org/fmit/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Music Instrument Tuner

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		fftw3:${PORTSDIR}/math/fftw3

BROKEN=		does not configure

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui opengl \
		linguist_build moc_build rcc_build uic_build
USE_GL=		glut
USE_CMAKE=	yes
CMAKE_ARGS=	-DSOUNDSYSTEM_USE_ALSA:BOOL=false
INSTALL_ICONS=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
