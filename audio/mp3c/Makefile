# New ports collection makefile for:	mp3c
# Date created:				11 Jul 2002
# Whom:					Joris Vandalon <joris@vandalon.nl>
#
# $FreeBSD$
#

PORTNAME=	mp3c
PORTVERSION=	0.27
CATEGORIES=	audio
MASTER_SITES=	ftp://excelsior.kullen.rwth-aachen.de/pub/linux/wspse/:src \
		http://www.cobweb.nl/wiebel/:script
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:src \
		cdrip.sh:script
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	joris@vandalon.nl
COMMENT=	A CD to mp3c converter with a console frontend

RUN_DEPENDS=	dagrab:${PORTSDIR}/audio/dagrab \
		gogo:${PORTSDIR}/audio/gogo \
		id3tool:${PORTSDIR}/audio/id3tool

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX}"

MAN1=		mp3c.1
MANCOMPRESSED=	no

post-install:
	${INSTALL_SCRIPT} ${DISTDIR}/cdrip.sh ${LOCALBASE}/bin

.include <bsd.port.mk>
