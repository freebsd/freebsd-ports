# New ports collection makefile for:  DBIx-Class-QueryProfiler
# Date created: 25 December 2009
# Whom: andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	DBIx-Class-QueryProfiler
PORTVERSION=	0.04
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBIx::Class profiler

BUILD_DEPENDS=	p5-Module-Install>=0:${PORTSDIR}/devel/p5-Module-Install
RUN_DEPENDS=	p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class
TEST_DEPENDS=	p5-Test-Perl-Critic>=0:${PORTSDIR}/devel/p5-Test-Perl-Critic

PERL_CONFIGURE=	5.8.9+

MAN3=		DBIx::Class::QueryProfiler.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001

BUILD_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS+=	p5-parent>=0:${PORTSDIR}/devel/p5-parent
.endif

.include <bsd.port.post.mk>
