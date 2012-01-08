# New ports collection makefile for:	p5-GDBM
# Date created:				Nov 9 1999
# Whom:	      				Nick Sayer <nsayer@FreeBSD.ORG>
#
# Heavy input from eivind@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	GDBM
PORTVERSION=	1.14
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN/../../src
PKGNAMEPREFIX=	p5-
DISTNAME=	perl-5.14.2
DIST_SUBDIR=	perl

MAINTAINER=	perl@FreeBSD.org
COMMENT=	GNU Data Base Manager (gdbm) interface

LIB_DEPENDS=	gdbm.4:${PORTSDIR}/databases/gdbm

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - ${DISTNAME}/ext/GDBM_File

CFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_SAFE=	yes
PERL_CONFIGURE=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/ext/GDBM_File

MAN3=		GDBM_File.3

.include <bsd.port.mk>
