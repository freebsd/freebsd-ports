# New ports collection makefile for:    TkRef
# Version required:     1.01
# Date created:         3 August 1997
# Whom:                 Bruce Gingery <bgingery@gtcs.com>
#
# $Id: Makefile,v 1.3 1998/02/21 22:38:09 fenner Exp $
#

DISTNAME=	tkref-1.01
CATEGORIES=	devel x11 tk81
MASTER_SITES=	http://gtcs.com/softdist/ \
		${MASTER_SITE_LOCAL}

MAINTAINER=	bgingery@gtcs.com

RUN_DEPENDS=	wish8.1:${PORTSDIR}/x11/tk81

NO_BUILD=	yes
NO_CONFIGURE=	yes

do-patch:
	perl -pi -e "s|/usr/local/bin/wish4.1|${PREFIX}/bin/wish8.1|;" \
		${WRKDIR}/TkRef

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/TkRef ${PREFIX}/bin

.include <bsd.port.mk>
