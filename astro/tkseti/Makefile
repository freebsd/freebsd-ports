# Ports collection makefile for:	tkseti
# Date created:		30 Jun 1999
# Whom:			Brett Taylor <brett@peloton.physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	tkseti
PORTVERSION=	3.07
CATEGORIES=	astro tk84
MASTER_SITES=	http://phileimer.9online.fr/tkseti/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk-based interface to SETI@Home

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		${LOCALBASE}/sbin/setiathome:${PORTSDIR}/astro/setiathome

NO_BUILD=	yes
USE_BZIP2=	yes

MAN1=	tkseti.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkseti ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tkseti.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tkseti
	${INSTALL_DATA}	${WRKSRC}/DOC ${PREFIX}/share/doc/tkseti/DOC
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tkseti/README
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
