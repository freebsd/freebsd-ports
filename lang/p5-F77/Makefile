# New ports collection makefile for:	p5-ExtUtils-F77
# Date created:				December 7 1999
# Whom:	      				jmz
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-F77
PORTVERSION=	1.14
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ExtUtils
PKGNAMEPREFIX=	p5-

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	Helps link C programs with Fortran subroutines

PERL_CONFIGURE=	yes

MAN3=		ExtUtils::F77.3

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400005
F2CLIB=	-lg2c
.else
F2CLIB=	-lf2c
.endif

post-patch:
	@cd ${WRKSRC}; ${PERL5} -i.orig -pe \
		's/(.*Freebsd.*lib )(-lf2c)(.*)/$$1 ${F2CLIB} $$3/' F77.pm

.include <bsd.port.post.mk>
