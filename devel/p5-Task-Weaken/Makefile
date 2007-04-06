# Ports collection makefile for:	p5-Task-Weaken
# Date created:				Apr 5, 2007
# Whom:					lbr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	Task-Weaken
PORTVERSION=	0.99
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Task
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Ensure that a platform has weaken support

PERL_CONFIGURE=	yes

MAN3=	Task::Weaken.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500805
IGNORE=	requires at least Perl 5.8.5. (Re-)install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
