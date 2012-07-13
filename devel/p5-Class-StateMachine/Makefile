# New ports collection makefile for:	devel/p5-Class-StateMachine
# Date created:				07 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-StateMachine
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Class::StateMachine - define classes for state machines

BUILD_DEPENDS=	p5-MRO-Define>=0.01:${PORTSDIR}/devel/p5-MRO-Define \
		p5-Package-Stash>=0.29:${PORTSDIR}/devel/p5-Package-Stash \
		p5-Sub-Name>=0.05:${PORTSDIR}/devel/p5-Sub-Name
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.10.1+

MAN3=		Class::StateMachine.3

.include <bsd.port.mk>
