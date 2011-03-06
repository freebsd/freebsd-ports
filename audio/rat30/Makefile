# New ports collection makefile for:   rat
# Date created:        6 June 2001
# Whom:                anton
#
# $FreeBSD$
#

PORTNAME=	rat
PORTVERSION=	3.0.35
PORTREVISION=	2
CATEGORIES=	audio mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rat/releases/${PORTVERSION}/ \
		CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IPv4/v6 Multicast and unicast audio conferencing tool

USE_TK=		82
USE_XORG=	x11 xext

WRKSRC=		${WRKDIR}/rat-3.0

USE_GMAKE=	yes
MAN1=		rat.1
PLIST_FILES=	bin/rat30

LATEST_LINK=	rat30

do-build:
	cd ${WRKSRC};${SETENV} ${MAKE_ENV} MAKE=${GMAKE} ${SH} ./Build rat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rat ${PREFIX}/bin/rat30
	${INSTALL_MAN} ${WRKSRC}/man/man1/rat.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
