# New ports collection makefile for:	Psion Link Protocol
# Date created:				Tue Nov 30 15:43:27 EST 1999
# Whom:					Maurice Castro <maurice@serc.rmit.edu.au>
#
# $FreeBSD$
#

PORTNAME=	plp
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.proudman51.freeserve.co.uk/psion/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kris
DISTNAME=	${PORTNAME}_1_8

MAINTAINER=	maurice@castro.aus.net
COMMENT=	Transfer data between a Psion Series 5(mx) and Unix

USE_GMAKE=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

pre-patch:
.for files in packet.cc socketchan.cc
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/ncp/${files}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ncp ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rfsv ${PREFIX}/bin

.include <bsd.port.post.mk>
