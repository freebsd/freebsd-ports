# New ports collection makefile for: 	hppsmtools
# Date created:		2 September 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	hppsmtools
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	http://unimut.fsk.uni-heidelberg.de/unimut/photosmart/ \
		http://www.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/

MAINTAINER=	anders@fix.no

ALL_TARGET=

do-install:
	@${RM} -f ${PREFIX}/bin/psmget ${PREFIX}/bin/psmdir
	@${RM} -f ${PREFIX}/bin/psmdel ${PREFIX}/bin/psmsho
	@${INSTALL_PROGRAM} ${WRKSRC}/psmget ${PREFIX}/bin/
	@${LN} ${PREFIX}/bin/psmget ${PREFIX}/bin/psmdir
	@${LN} ${PREFIX}/bin/psmget ${PREFIX}/bin/psmdel
	@${LN} ${PREFIX}/bin/psmget ${PREFIX}/bin/psmsho
	@${INSTALL} -d -m 0755 ${PREFIX}/share/doc/hppsmtools
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/hppsmtools/

.include <bsd.port.mk>
