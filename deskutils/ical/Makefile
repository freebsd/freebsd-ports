# New ports collection makefile for:    ical
# Version required:     1.9
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.1.1.1 1995/08/23 09:45:12 asami Exp $
#

DISTNAME=	ical-1.9
CATEGORIES+=	utilities
MASTER_SITES=	ftp://ftp.sterling.com/programming/languages/tcl/code/ical/

LIB_DEPENDS=    tcl\\.7\\.:${PORTSDIR}/lang/tcl \
                tk\\.3\\.:${PORTSDIR}/x11/tk 

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX)

.include <bsd.port.mk>
