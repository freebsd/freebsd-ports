# New ports collection makefile for:	zynaddsubfx
# Date created:		2007-01-25
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	zynaddsubfx
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	zynaddsubfx
DISTNAME=	ZynAddSubFX-${PORTVERSION}

PATCH_SITES=	http://www.student.nada.kth.se/~d00-llu/code_patches/
PATCHFILES=	zyn-jackmidi-051205.diff
PATCH_DIST_STRIP=	-p2

MAINTAINER=	trasz@freebsd.org
COMMENT=	A realtime software synthesizer

LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		fftw3.4:${PORTSDIR}/math/fftw3 \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		expat.6:${PORTSDIR}/textproc/expat2 \
		jack.0:${PORTSDIR}/audio/jack
BUILD_DEPENDS=	${LOCALBASE}/include/mxml.h:${PORTSDIR}/textproc/mini-xml

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		Does not compile on 4.x and 5.x
.endif

.include <bsd.port.post.mk>
