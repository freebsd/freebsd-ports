# New ports collection makefile for:	expect
# Version required:	5.12
# Date created:		20 November 1994
# Whom:			pst
#
# $Id: Makefile,v 1.3 1995/02/11 13:49:44 asami Exp $
#

DISTNAME=	expect-5.13
MASTER_SITES=	ftp://ftp.cme.nist.gov/pub/expect/
CATEGORIES+=	languages
DISTFILES=	expect.tar.gz
HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

LIB_DEPENDS=	tcl\\.7\\.:${PORTSDIR}/lang/tcl \
		tk\\.3\\.:${PORTSDIR}/x11/tk

.include <bsd.port.mk>
