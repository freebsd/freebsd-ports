# New ports collection makefile for:	expect
# Date created:		20 November 1994
# Whom:			pst
#
# $FreeBSD$

PORTNAME=	expect
PORTVERSION=	5.31.8
CATEGORIES=	lang tcl82 tk82
MASTER_SITES=	http://expect.nist.gov/
DISTNAME=	expect

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS?=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/expect-5.31
INSTALLS_SHLIBS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?= --enable-shared \
		--with-tclconfig=${PREFIX}/lib/tcl8.2 \
		--with-tclinclude=${PREFIX}/include/tcl8.2 \
		--with-tkconfig=${PREFIX}/lib/tk8.2 \
		--with-tkinclude=${PREFIX}/include/tk8.2
.if !defined(NO_MAN_INSTALL)
MAN1=		autoexpect.1 cryptdir.1 decryptdir.1 dislocate.1 \
		expect.1 expectk.1 kibitz.1 mkpasswd.1 passmass.1 \
		tknewsbiff.1 unbuffer.1 xkibitz.1
MAN3=		libexpect.3
.endif

post-install:
	${LN} -sf libexpect531.so.1 ${PREFIX}/lib/libexpect531.so

.include <bsd.port.mk>
