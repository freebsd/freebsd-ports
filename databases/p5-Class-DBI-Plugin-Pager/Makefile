# New ports collection makefile for:	Class-DBI-Plugin-Pager
# Date created:		25 Oct 2005
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Plugin-Pager
PORTVERSION=	0.561
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to paged queries for CDBI

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/SQL/Abstract.pm:${PORTSDIR}/databases/p5-SQL-Abstract \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		${SITE_PERL}/Data/Page.pm:${PORTSDIR}/databases/p5-Data-Page

PERL_CONFIGURE=	yes
MAN3=		Class::DBI::Plugin::Pager.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	perl 5.6 or newer required by Class::DBI. Install lang/perl5.8 or lang/perl5 and try again
.endif

.include <bsd.port.post.mk>
