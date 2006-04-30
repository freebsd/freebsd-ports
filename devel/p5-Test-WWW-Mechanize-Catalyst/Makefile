# Ports collection makefile for:	p5-Test-WWW-Mechanize-Catalyst
# Date created:				Nov 16, 2005
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	Test-WWW-Mechanize-Catalyst
PORTVERSION=	0.36
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/L/LB/LBROCARD
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	Test::WWW::Mechanize for Catalyst

RUN_DEPENDS=	p5-Catalyst>=5.00:${PORTSDIR}/www/p5-Catalyst \
		p5-Test-WWW-Mechanize>=1.04:${PORTSDIR}/devel/p5-Test-WWW-Mechanize
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

PERL_MODBUILD=	yes

MAN3=	Test::WWW::Mechanize::Catalyst.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
