# New ports collection makefile for:	zynaddsubfx
# Date created:		2007-01-25
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	zynaddsubfx
PORTVERSION=	2.2.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	zynaddsubfx
DISTNAME=	ZynAddSubFX-${PORTVERSION}

PATCH_SITES=	http://www.student.nada.kth.se/~d00-llu/code_patches/
PATCHFILES=	zyn-jackmidi-051205.diff
PATCH_DIST_STRIP=	-p2

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	A realtime software synthesizer

LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		fftw3.5:${PORTSDIR}/math/fftw3 \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		expat.6:${PORTSDIR}/textproc/expat2 \
		jack.0:${PORTSDIR}/audio/jack
BUILD_DEPENDS=	${LOCALBASE}/include/mxml.h:${PORTSDIR}/textproc/mini-xml \
		jackit>=0.109.2:${PORTSDIR}/audio/jack

# Between 0.109.0 and earlier versions there was an api change in JACK.
# However, the library version number was not changed.  The line above
# is supposed to work around that.

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_BZIP2=	yes
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/dssi

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/zynaddsubfx ${PREFIX}/bin
		${MKDIR} ${DATADIR}
		${MKDIR} ${DATADIR}/banks
		cd ${WRKDIR}/${DISTNAME}/banks && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/banks/{} \;
		cd ${WRKDIR}/${DISTNAME}/banks && ${FIND} . -type f \
			-exec ${INSTALL_DATA} {} ${DATADIR}/banks/{} \;
		${MKDIR} ${DATADIR}/presets
		cd ${WRKDIR}/${DISTNAME}/presets && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/presets/{} \;
		cd ${WRKDIR}/${DISTNAME}/presets && ${FIND} . -type f \
			-exec ${INSTALL_DATA} {} ${DATADIR}/presets/{} \;

.include <bsd.port.mk>
