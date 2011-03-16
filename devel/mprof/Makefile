# ex:ts=8
# Ports collection makefile for:  mprof
# Date created:			  Sat Nov  5 01:16:33 PST 1994
# Whom:				  hsu
#
# $FreeBSD$
#

PORTNAME=	mprof
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.colorado.edu/pub/misc/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Memory Profiler and Leak Detector

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_WRKSUBDIR=	yes
MAKEFILE=	Makefile.i386
MAN1=		mprof.1
PLIST_FILES=	bin/mprof lib/libc_mp.a

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mprof ${PREFIX}/bin
	${INSTALL} ${COPY} -m 555 ${WRKSRC}/libc_mp.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/mprof.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
