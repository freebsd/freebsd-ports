# New ports collection makefile for:  rat
# Date created:			      3 July 1999
# Whom:				      O.Hodson@cs.ucl.ac.uk (Orion Hodson)
#
# $FreeBSD$
#

PORTNAME=	rat
PORTVERSION=	4.0.4
CATEGORIES=	mbone audio
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/4.0.4/ \
		http://people.FreeBSD.org/~cpiazza/distfiles/

MAINTAINER=	O.Hodson@cs.ucl.ac.uk

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

USE_GMAKE=	yes
MAN1=		rat.1
MANCOMPRESSED=	no

RAT_BUILD_DIRS=	common rat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rat/rat-4.0.4 ${PREFIX}/bin/rat
	${INSTALL_MAN}  ${WRKSRC}/rat/man/man1/rat.1 ${PREFIX}/man/man1
	${MKDIR} ${LOCALBASE}/etc/sdr/plugins
	${INSTALL_DATA} ${WRKSRC}/rat/sdr2.plugin.S02.audio.rtp.*.rat-4.0.4 ${LOCALBASE}/etc/sdr/plugins

do-build:
	for d in ${RAT_BUILD_DIRS}; do \
		cd ${WRKSRC}/$$d && ${GMAKE}; \
	done

do-configure:
	for d in ${RAT_BUILD_DIRS}; do \
		cd ${WRKSRC}/$$d && ./configure; \
	done

.include "bsd.port.mk"
