# New ports collection makefile for:	devel/p5-CPAN-YACSmoke
# Date created:				3 March 2005
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CPAN-YACSmoke
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RR/RRWO
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Yet Another CPAN Smoke Tester

BUILD_DEPENDS=	${SITE_PERL}/CPANPLUS.pm:${PORTSDIR}/devel/p5-CPANPLUS \
		${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable \
		${SITE_PERL}/Test/Reporter.pm:${PORTSDIR}/devel/p5-Test-Reporter \
		${SITE_PERL}/Sort/Versions.pm:${PORTSDIR}/devel/p5-Sort-Versions \
		${SITE_PERL}/Regexp/Assemble.pm:${PORTSDIR}/devel/p5-Regexp-Assemble \
		${SITE_PERL}/File/HomeDir.pm:${PORTSDIR}/devel/p5-File-HomeDir
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CPAN::YACSmoke.3 \
		CPAN::YACSmoke::Plugin::SmokeDB.3 \
		CPAN::YACSmoke::Plugin::Recent.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	"Needs perl 5.6.1 or higher, install lang/perl5 or lang/perl5.8 and try again"
.endif

.include <bsd.port.post.mk>
