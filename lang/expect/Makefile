# New ports collection makefile for:	expect
# Date created:		20 November 1994
# Whom:			pst
# Version required:	5.25
#
# $Id: Makefile,v 1.28 1997/12/29 11:42:10 asami Exp $
#

DISTNAME=	expect
PKGNAME=	expect-5.25
CATEGORIES=	lang tcl80 tk80
MASTER_SITES=	http://expect.nist.gov/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80

WRKSRC=		${WRKDIR}/expect-5.25

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-shared \
		--with-tclconfig=${PREFIX}/lib/tcl8.0 \
		--with-tclinclude=${PREFIX}/include/tcl8.0 \
		--with-tkconfig=${PREFIX}/lib/tk8.0 \
		--with-tkinclude=${PREFIX}/include/tk8.0
# needed for japanese/expect
.if !defined(NO_MAN_INSTALL)
MAN1=		autoexpect.1 cryptdir.1 decryptdir.1 dislocate.1 \
		expect.1 expectk.1 kibitz.1 mkpasswd.1 passmass.1 \
		tknewsbiff.1 unbuffer.1 xkibitz.1
MAN3=		libexpect.3
.endif

test:
	@(cd ${WRKSRC}; make test)

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
