# New ports collection makefile for:	expect
# Version required:	5.18
# Date created:		20 November 1994
# Whom:			pst
#
# $Id: Makefile,v 1.8 1995/12/07 22:18:09 markm Exp $
#

DISTNAME=	expect-5.19
CATEGORIES+=	lang
MASTER_SITES=	ftp://ftp.cme.nist.gov/pub/expect/
DISTFILES=	expect.tar.gz

DEPENDS=        ${PORTSDIR}/lang/tcl ${PORTSDIR}/x11/tk
LIB_DEPENDS=	tcl\\.7\\.:${PORTSDIR}/lang/tcl \
		tk\\.3\\.:${PORTSDIR}/x11/tk

test:
	@(cd ${WRKSRC}; make test)

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
