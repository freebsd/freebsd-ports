# New ports collection makefile for:    p5-GDBM
# Date created:				Nov 9 1999
# Whom:	      				Nick Sayer <nsayer@FreeBSD.ORG>
#
# Heavy input from eivind@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	p5-GDBM
PORTVERSION=	1.00
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../src
DISTNAME=	perl5.005_03

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to use the GNU Data Base Manager (gdbm)

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

PERL_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/ext/GDBM_File

MAN3=		GDBM_File.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500800
BROKEN=		"Does not compile
.endif

.include <bsd.port.post.mk>
