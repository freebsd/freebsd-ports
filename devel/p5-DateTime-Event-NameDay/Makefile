# New ports collection makefile for:	p5-DateTime-Event-NameDay
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Event-NameDay
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl DateTime extension to work with namedays from various countries

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Set.pm:${PORTSDIR}/devel/p5-DateTime-Set \
		${SITE_PERL}/DateTime/Calendar/Christian.pm:${PORTSDIR}/devel/p5-DateTime-Calendar-Christian \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

# Depends on p5-DateTime-Set which requires perl >= 5.6
.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
