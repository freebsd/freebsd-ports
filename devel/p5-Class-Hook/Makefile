# New ports collection makefile for:	p5-Class-Hook
# Date created:			Fri Nov  7 19:40:58 EST 2002
# Whom:				Brian Skrab <brian@quynh-and-brian.org>
#
# $FreeBSD$
#

PORTNAME=		Class-Hook
PORTVERSION=		0.02
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN} \
			http://cottage.quynh-and-brian.org/freebsd/ports/distfiles/
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=		p5-

MAINTAINER=		perl@FreeBSD.org
COMMENT=		Add hooks on methods from other classes

BUILD_DEPENDS=		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
			${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/Class-Hook

MAN3=			Class::Hook.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
