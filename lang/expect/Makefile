# New ports collection makefile for:	expect
# Date created:		20 November 1994
# Whom:			pst
# Version required:	5.22.0
#
# $Id: Makefile,v 1.19 1997/04/20 13:19:07 wosch Exp $
#

DISTNAME=	expect-5.22
PKGNAME=	expect-5.22.0
CATEGORIES=	lang tcl76 tk42
MASTER_SITES=	http://expect.nist.gov/ \
		ftp://expect.nist.gov/mel/div826/subject/expect/
DISTFILES=	expect.tar.gz

LIB_DEPENDS=	tk42\\.1\\.:${PORTSDIR}/x11/tk42

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib/tcl7.6 \
		--with-tclinclude=${PREFIX}/include/tcl7.6 \
		--with-tkconfig=${PREFIX}/lib/tk4.2 \
		--with-tkinclude=${PREFIX}/include/tk4.2
MAN1=		autoexpect.1 cryptdir.1 decryptdir.1 dislocate.1 \
		expect.1 expectk.1 kibitz.1 mkpasswd.1 passmass.1 \
		tknewsbiff.1 unbuffer.1 xkibitz.1
MAN3=		libexpect.3

test:
	@(cd ${WRKSRC}; make test)

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
