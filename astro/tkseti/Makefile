# Ports collection makefile for:	tkseti
# Version required:	1.36
# Date created:		30 Jun 1999
# Whom:			Brett Taylor <brett@peloton.physics.montana.edu>
#
# $FreeBSD$
#

DISTNAME=	tkseti-1.42
CATEGORIES=	astro tk80
MASTER_SITES=	http://www.cuug.ab.ca/~macdonal/tkseti/

MAINTAINER=	brett@peloton.physics.montana.edu

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80 \
		setiathome:${PORTSDIR}/astro/setiathome

NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/share/doc/tkseti
	${INSTALL_SCRIPT} ${WRKSRC}/tkseti ${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/DOC ${PREFIX}/share/doc/tkseti/DOC
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tkseti/README

post-install:
	@${ECHO} "Please read the documentation for tkseti located in"
	@${ECHO} "${PREFIX}/share/doc/tkseti/DOC and ${PREFIX}/share/doc/tkseti/README."

.include <bsd.port.mk>
