# New ports collection makefile for:	games/ttraffic
# Date created:				14 November 2001
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttraffic
PORTVERSION=	0.8
CATEGORIES=	games
MASTER_SITES=	http://alpha.luc.ac.be/Research/Algebra/Members/Ttraffic/ \
		http://www.tobez.org/download/port-mirrors/games/ttraffic/

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

NO_BUILD=	yes

post-patch:
	${PERL} -pi -e 's|/usr/local/share/ttraffic/|${DATADIR}/|g;' \
		-e 's|#!/usr/bin/wish|#!${LOCALBASE}/bin/wish8.3|g' \
		${WRKSRC}/ttraffic.tcl
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ttraffic.tcl ${PREFIX}/bin/ttraffic
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ttraffic.levels ${DATADIR}

.include <bsd.port.mk>
