# New ports collection makefile for:    ical
# Version required:     1.9
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.3 1995/10/28 20:33:18 erich Exp $
#

DISTNAME=	ical-1.9
CATEGORIES+=	misc
MASTER_SITES=	ftp://ftp.sterling.com/programming/languages/tcl/code/ical/

MAINTAINER=	erich@FreeBSD.org

LIB_DEPENDS=    tcl\\.7\\.:${PORTSDIR}/lang/tcl \
                tk\\.3\\.:${PORTSDIR}/x11/tk 

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX)

.include <bsd.port.mk>
