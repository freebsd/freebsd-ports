# New ports collection makefile for:	p5-GDBM
# Date created:				Nov 9 1999
# Whom:	      				Nick Sayer <nsayer@FreeBSD.ORG>
#
# Heavy input from eivind@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	GDBM
PORTVERSION=	1.09
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN/../../src
PKGNAMEPREFIX=	p5-
DISTNAME=	perl-5.8.9
DIST_SUBDIR=	perl

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	GNU Data Base Manager (gdbm) interface

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

MAKE_JOBS_SAFE=  yes

USE_BZIP2=	yes
PERL_CONFIGURE=	5.8.0+
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - ${DISTNAME}/ext/GDBM_File
WRKSRC=		${WRKDIR}/${DISTNAME}/ext/GDBM_File
CFLAGS=		-I${LOCALBASE}/include
MAN3=		GDBM_File.3

post-patch:
	@${REINPLACE_CMD} -e '/MAN3PODS/s|.*||' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
