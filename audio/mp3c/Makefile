# New ports collection makefile for:   oneko
# Date created:        5 December 1994
# Whom:                asami
#
# $FreeBSD$
#

PORTNAME=      mp3c
PORTVERSION=   0.27
CATEGORIES=    audio
MASTER_SITES=	ftp://excelsior.kullen.rwth-aachen.de/pub/linux/wspse/

MAINTAINER=    wiebel@FreeBSD.nl

RUN_DEPENDS=   dagrab:${PORTSDIR}/audio/dagrab \
	       gogo:${PORTSDIR}/audio/gogo \
	       id3tool:${PORTSDIR}/audio/id3tool

HAS_CONFIGURE= yes
CONFIGURE_ARGS="--prefix=${PREFIX}"

MAN1=          mp3c.1
MANCOMPRESSED= no

post-install:
	${FETCH_CMD} -o ${LOCALBASE}/bin/cdrip.sh http://www.cobweb.nl/wiebel/cdrip.sh
	${CHMOD} +x ${LOCALBASE}/bin/cdrip.sh

.include <bsd.port.mk>
