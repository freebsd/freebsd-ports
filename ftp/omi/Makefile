# New ports collection makefile for:    omi
# http://fromme.com/omi/
# Version required:     alpha
# Date created:		19 August 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.3 1998/07/24 10:49:34 ache Exp $
#

DISTNAME=       omi-alpha-9
CATEGORIES=	net
MASTER_SITES=   http://dorifer.heim3.tu-clausthal.de/~olli/omi/

MAINTAINER=     ache@FreeBSD.org

ALL_TARGET=     freebsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omi ${PREFIX}/bin
	${INSTALL} -d -m 755 -o ${DOCOWN} -g ${DOCGRP} \
		${PREFIX}/share/doc/omi
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/omi
	${INSTALL_DATA} ${WRKSRC}/README.html ${PREFIX}/share/doc/omi
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/omi
	${INSTALL_DATA} ${WRKSRC}/BSD-COPYRIGHT ${PREFIX}/share/doc/omi

.include <bsd.port.mk>
