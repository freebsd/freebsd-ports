# New ports collection makefile for:	expect
# Date created:		20 November 1994
# Whom:			pst
#
# $FreeBSD$

PORTNAME=	expect
PORTVERSION=	5.32.1
CATEGORIES=	lang tcl83 tk83
MASTER_SITES=	http://expect.nist.gov/
DISTNAME=	expect

MAINTAINER=	john@coastalgeology.org

LIB_DEPENDS?=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

WRKSRC=		${WRKDIR}/expect-5.32
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?= --enable-shared \
		--with-tclconfig=${PREFIX}/lib/tcl8.3 \
		--with-tclinclude=${PREFIX}/include/tcl8.3 \
		--with-tkconfig=${PREFIX}/lib/tk8.3 \
		--with-tkinclude=${PREFIX}/include/tk8.3
.if !defined(NO_MAN_INSTALL)
MAN1=		autoexpect.1 cryptdir.1 decryptdir.1 dislocate.1 \
		expect.1 expectk.1 kibitz.1 mkpasswd.1 passmass.1 \
		tknewsbiff.1 unbuffer.1 xkibitz.1
MAN3=		libexpect.3
.endif

post-install:
	${LN} -sf libexpect532.so.1 ${PREFIX}/lib/libexpect532.so

.include <bsd.port.mk>
