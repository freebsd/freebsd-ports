# New ports collection makefile for:	expect
# Version required:	5.21
# Date created:		20 November 1994
# Whom:			pst
#
# $Id: Makefile,v 1.13 1996/11/18 14:02:23 asami Exp $
#

DISTNAME=	expect-5.21
CATEGORIES=	lang
MASTER_SITES=	http://expect.nist.gov/ \
		ftp://expect.nist.gov/mel/div826/subject/expect/
DISTFILES=	expect.tar.gz

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared --with-tclconfig=/usr/libdata/tcl \
		--with-tclinclude=/usr/include/tcl
MAN1=		autoexpect.1 cryptdir.1 decryptdir.1 dislocate.1 \
		expect.1 expectk.1 kibitz.1 mkpasswd.1 passmass.1 \
		tknewsbiff.1 unbuffer.1 xkibitz.1
MAN3=		libexpect.3

test:
	@(cd ${WRKSRC}; make test)

# Sigh, all this just to get tkInt.h..
post-extract:
	(cd ${PORTSDIR}/x11/tk41 && make extract)
	ln -s ${PORTSDIR}/x11/tk41/work/tk* ${WRKDIR}

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
