# New ports collection makefile for:	expect
# Version required:	5.18
# Date created:		20 November 1994
# Whom:			pst
#
# $Id: Makefile,v 1.7 1995/11/22 13:12:38 asami Exp $
#

DISTNAME=	expect-5.18
CATEGORIES+=	lang
MASTER_SITES=	ftp://ftp.cme.nist.gov/pub/expect/
DISTFILES=	expect.tar.gz

LIB_DEPENDS=	tcl\\.7\\.:${PORTSDIR}/lang/tcl \
		tk\\.3\\.:${PORTSDIR}/x11/tk

test:
	@(cd ${WRKSRC}; make test)

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
