# New ports collection makefile for:   rat
# Date created:        6 June 2001
# Whom:                anton
#
# $FreeBSD$
#

PORTNAME=	rat
PORTVERSION=	3.0.35
PORTREVISION=	1
CATEGORIES=	mbone audio
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/releases/${PORTVERSION}/

MAINTAINER=	anton@chelcom.ru
COMMENT=	IPv4/v6 Multicast and unicast audio conferencing tool

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/rat-3.0

USE_GMAKE=	yes
MAN1=		rat.1
MANCOMPRESSED=	no

LATEST_LINK=	rat30

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

do-build:
	(cd ${WRKSRC};${SETENV} ${MAKE_ENV} MAKE=${GMAKE} ${SH} ./Build rat)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rat ${PREFIX}/bin/rat30
	${INSTALL_MAN}  ${WRKSRC}/man/man1/rat.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
