# New ports collection makefile for:	expect
# Date created:		20 November 1994
# Whom:			pst
# Version required:	5.26
#
# $Id: Makefile,v 1.32 1998/06/28 23:25:51 steve Exp $
#
# Note this file is included from japanese/extract/Makefile

DISTNAME=	expect-5.26
CATEGORIES=	lang tcl80 tk80
MASTER_SITES=	ftp://peloton.physics.montana.edu/pub/distfiles/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS?=	tk80\\.1:${PORTSDIR}/x11-toolkits/tk80

GNU_CONFIGURE=	yes
CONFIGURE_ARGS?= --enable-shared \
		--with-tclconfig=${PREFIX}/lib/tcl8.0 \
		--with-tclinclude=${PREFIX}/include/tcl8.0 \
		--with-tkconfig=${PREFIX}/lib/tk8.0 \
		--with-tkinclude=${PREFIX}/include/tk8.0
.if !defined(NO_MAN_INSTALL)
MAN1=		autoexpect.1 cryptdir.1 decryptdir.1 dislocate.1 \
		expect.1 expectk.1 kibitz.1 mkpasswd.1 passmass.1 \
		tknewsbiff.1 unbuffer.1 xkibitz.1
MAN3=		libexpect.3
.endif

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
