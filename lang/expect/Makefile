# New ports collection makefile for:	expect
# Date created:		20 November 1994
# Whom:			pst
# Version required:	5.28
#
# $Id: Makefile,v 1.36 1998/10/05 05:02:28 steve Exp $
#
# Note this file is included from japanese/expect/Makefile

DISTNAME=	expect-5.28
CATEGORIES=	lang tcl80 tk80
MASTER_SITES=	ftp://peloton.physics.montana.edu/pub/distfiles/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS?=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

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
	${LN} -sf ${SOLIB} ${PREFIX}/lib/libexpect528.so
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

.if ${PORTOBJFORMAT} == "elf"
SOLIB=	libexpect528.so.1
.else
SOLIB=	libexpect528.so.1.2
.endif
