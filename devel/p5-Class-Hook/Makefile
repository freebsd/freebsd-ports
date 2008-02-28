# New ports collection makefile for:	p5-Class-Hook
# Date created:			Fri Nov  7 19:40:58 EST 2002
# Whom:				Brian Skrab <brian@quynh-and-brian.org>
#
# $FreeBSD$
#

PORTNAME=		Class-Hook
PORTVERSION=		0.02
PORTREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		CPAN \
			http://cottage.quynh-and-brian.org/freebsd/ports/distfiles/
PKGNAMEPREFIX=		p5-

MAINTAINER=		perl@FreeBSD.org
COMMENT=		Add hooks on methods from other classes

PERL_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/Class-Hook

MAN3=			Class::Hook.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=		p5-Time-HiRes>=0.01:${PORTSDIR}/devel/p5-Time-HiRes
.endif

.include <bsd.port.post.mk>
