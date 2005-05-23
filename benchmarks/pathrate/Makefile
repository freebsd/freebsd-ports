# New ports collection makefile for:	pathrate
# Date created:			19 May 2005
# Whom:				dikshie <dikshie@lapi.itb.ac.id>
#
# $FreeBSD$
#

PORTNAME=	pathrate
PORTVERSION=	2.4.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.cc.gatech.edu/fac/Constantinos.Dovrolis/
DISTNAME=	${PORTNAME}

MAINTAINER=	dikshie@lapi.itb.ac.id
COMMENT=	A measurement tool for capacity estimation of network paths

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
MAKEFILE=	makefile

PLIST_FILES=	bin/pathrate_rcv bin/pathrate_snd

do-install:
.for f in pathrate_rcv pathrate_snd
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
