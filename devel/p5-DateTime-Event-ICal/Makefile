# New ports collection makefile for:	p5-DateTime-Event-ICal
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Event-ICal
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl DateTime extension for computing rfc2445 recurrences

BUILD_DEPENDS=	${SITE_PERL}/DateTime/Event/Recurrence.pm:${PORTSDIR}/devel/p5-DateTime-Event-Recurrence \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Set.pm:${PORTSDIR}/devel/p5-DateTime-Set \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Event::ICal.3

.include <bsd.port.pre.mk>

# Depends on p5-DateTime-Set which requires perl 5.6
.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
