# New ports collection makefile for:    p5-GDBM
# Version required:			1.0
# Date created:				Nov 9 1999
# Whom:	      				Nick Sayer <nsayer@FreeBSD.ORG>
#
# Heavy input from eivind@freebsd.org
#
# $FreeBSD$
#

DISTNAME=       perl5.005_03
PKGNAME=        p5-GDBM-1.00
CATEGORIES=     databases perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=   ../../src

MAINTAINER=	nsayer@FreeBSD.ORG

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

USE_PERL5=	YES

WRKSRC=         ${WRKDIR}/${DISTNAME}/ext/GDBM_File

MAN3=           GDBM_File.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.pre.mk>

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.post.mk>
