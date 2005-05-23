# New ports collection makefile for:	pathload
# Date created:			19 May 2005
# Whom:				dikshie <dikshie@lapi.itb.ac.id>
#
# $FreeBSD$
#

PORTNAME=	pathload
PORTVERSION=	1.2
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.cc.gatech.edu/fac/Constantinos.Dovrolis/
DISTNAME=	${PORTNAME}

MAINTAINER=	dikshie@lapi.itb.ac.id
COMMENT=	A measurement tool for network path available bandwidth estimation

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
MAKEFILE=	makefile

PLIST_FILES=	bin/pathload_rcv bin/pathload_snd

do-install:
.for f in pathload_rcv pathload_snd
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
