# New ports collection makefile for:	expect
# Version required:	5.12
# Date created:		20 November 1994
# Whom:			pst
#
# $Id: Makefile,v 1.6 1995/05/09 08:50:45 hsu Exp $
#

DISTNAME=	expect-5.16
CATEGORIES+=	lang
MASTER_SITES=	ftp://ftp.cme.nist.gov/pub/expect/
DISTFILES=	expect.tar.gz

LIB_DEPENDS=	tcl\\.7\\.:${PORTSDIR}/lang/tcl \
		tk\\.3\\.:${PORTSDIR}/x11/tk

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
