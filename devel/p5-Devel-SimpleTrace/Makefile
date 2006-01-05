# New ports collection makefile for:   p5-Devel-SimpleTrace
# Date created:        4 January 2006
# Whom:                estith
#
# $FreeBSD$
#

PORTNAME=	Devel-SimpleTrace
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	estith.freebsd.ports@thelunarempire.net
COMMENT=	Perl module for better stack traces on interpretter-generated warn/die

PERL_CONFIGURE=	yes

MAN3=		Devel::SimpleTrace.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
