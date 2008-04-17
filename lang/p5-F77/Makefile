# New ports collection makefile for:	p5-ExtUtils-F77
# Date created:				December 7 1999
# Whom:	      				jmz
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-F77
PORTVERSION=	1.15
PORTREVISION=	2
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	Helps link C programs with Fortran subroutines

PERL_CONFIGURE=	yes

MAN3=		ExtUtils::F77.3

F2CLIB=		-lg2c

post-patch:
	@cd ${WRKSRC}; ${PERL5} -i.orig -pe \
		's/(.*Freebsd.*lib )(-lf2c)(.*)/$$1 ${F2CLIB} $$3/' F77.pm
	@${REINPLACE_CMD} -e "s/'f77',/'f77','g77-34',/" ${WRKSRC}/F77.pm

.include <bsd.port.mk>
