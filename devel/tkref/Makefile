# New ports collection makefile for:    TkRef
# Version required:     1.01
# Date created:         3 August 1997
# Whom:                 Bruce Gingery <bgingery@gtcs.com>
#
# $Id: Makefile,v 1.6 1998/06/27 05:18:53 asami Exp $
#

DISTNAME=	tkref-1.01
CATEGORIES=	devel tk80
MASTER_SITES=	http://gtcs.com/softdist/ \
		${MASTER_SITE_LOCAL}

MAINTAINER=	bgingery@gtcs.com

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

NO_BUILD=	yes

do-patch:
	perl -pi -e "s|/usr/local/bin/wish4.1|${PREFIX}/bin/wish8.0|;" \
		${WRKDIR}/TkRef

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/TkRef ${PREFIX}/bin

.include <bsd.port.mk>
