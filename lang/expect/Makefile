# New ports collection makefile for:	expect
# Version required:	5.18
# Date created:		20 November 1994
# Whom:			pst
#
# $Id: Makefile,v 1.9 1996/02/07 05:10:25 jkh Exp $
#

DISTNAME=	expect-5.19
CATEGORIES+=	lang
MASTER_SITES=	ftp://ftp.cme.nist.gov/pub/expect/
DISTFILES=	expect.tar.gz

LIB_DEPENDS=	tcl\\.7\\.:${PORTSDIR}/lang/tcl \
		tk\\.3\\.:${PORTSDIR}/x11/tk

test:
	@(cd ${WRKSRC}; make test)

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

post-extract:
	(cd ${PORTSDIR}/lang/tcl && make extract)
	ln -s ${PORTSDIR}/lang/tcl/work/tcl* ${WRKDIR}
	(cd ${PORTSDIR}/x11/tk && make extract)
	ln -s ${PORTSDIR}/x11/tk/work/tk* ${WRKDIR}

pre-install:
	test -d ${PREFIX}/lib/expect || mkdir -p ${PREFIX}/lib/expect

.include <bsd.port.mk>
