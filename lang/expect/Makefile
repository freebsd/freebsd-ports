# New ports collection makefile for:	expect
# Date created:		20 November 1994
# Whom:			pst
# Version required:	5.22.0
#
# $Id: Makefile,v 1.18 1997/03/11 11:42:14 asami Exp $
#

DISTNAME=	expect-5.22
PKGNAME=	expect-5.22.0
CATEGORIES=	lang tk41
MASTER_SITES=	http://expect.nist.gov/ \
		ftp://expect.nist.gov/mel/div826/subject/expect/
DISTFILES=	expect.tar.gz

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared --with-tclconfig=/usr/libdata/tcl \
		--with-tclinclude=/usr/include/tcl \
		--with-tkinclude=${PREFIX}/include/tk4.1
MAN1=		autoexpect.1 cryptdir.1 decryptdir.1 dislocate.1 \
		expect.1 expectk.1 kibitz.1 mkpasswd.1 passmass.1 \
		tknewsbiff.1 unbuffer.1 xkibitz.1
MAN3=		libexpect.3

test:
	@(cd ${WRKSRC}; make test)

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
