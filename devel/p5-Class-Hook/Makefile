# New ports collection makefile for:	p5-Class-Hook
# Date created:			Fri Nov  7 19:40:58 EST 2002
# Whom:				Brian Skrab <brian@quynh-and-brian.org>
#
# $FreeBSD$
#

PORTNAME=		Class-Hook
PORTVERSION=		0.01
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN} \
			http://cottage.quynh-and-brian.org/freebsd/ports/distfiles/
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=		p5-

MAINTAINER=		brian@quynh-and-brian.org
COMMENT=		Add hooks on methods from other classes

BUILD_DEPENDS=		${ARCH_PERL}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
			${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=		yes

MAN3=			Class::Hook.3

ARCH_PERL=		${SITE_PERL}/${PERL_ARCH}

post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/' \
		${WRKSRC}/lib/Class/Hook.pm

.include <bsd.port.mk>
