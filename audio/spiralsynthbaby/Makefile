# New ports collection makefile for:	spiralsynth
# Date created:				2000-09-05
# Whom:					Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=	spiralsynth
PORTVERSION=	0.1.7
CATEGORIES=	audio
MASTER_SITES=	http://www.pawfal.org/SpiralSynth/dload/
DISTNAME=	SpiralSynth-${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_X_PREFIX=	yes

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

DOC_FILES=	CHANGES COPYING README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralSynth ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/spiralsynth
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/spiralsynth
.endfor
.endif
.include <bsd.port.mk>
