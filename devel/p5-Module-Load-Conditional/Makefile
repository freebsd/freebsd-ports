# New ports collection makefile for:	devel/p5-Module-Load-Conditional
# Date created:				15 December 2004
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Load-Conditional
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Looking up Perl modules information/loading at runtime

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Module/Load.pm:${PORTSDIR}/devel/p5-Module-Load \
		${SITE_PERL}/Locale/Maketext/Simple.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		${SITE_PERL}/Params/Check.pm:${PORTSDIR}/devel/p5-Params-Check
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Module::Load::Conditional.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500600
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

.include <bsd.port.post.mk>
