# New ports collection makefile for:	expect
# Version required:	5.21
# Date created:		20 November 1994
# Whom:			pst
#
# $Id: Makefile,v 1.10 1996/02/07 09:36:41 asami Exp $
#

DISTNAME=	expect-5.21
CATEGORIES+=	lang
MASTER_SITES=	http://expect.nist.gov/ \
		ftp://expect.nist.gov/mel/div826/subject/expect/
DISTFILES=	expect.tar.gz

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

test:
	@(cd ${WRKSRC}; make test)

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared --with-tclconfig=/usr/libdata/tcl \
		--with-tclinclude=/usr/include/tcl

# Sigh, all this just to get tkInt.h..
post-extract:
	(cd ${PORTSDIR}/x11/tk41 && make extract)
	ln -s ${PORTSDIR}/x11/tk41/work/tk* ${WRKDIR}

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
