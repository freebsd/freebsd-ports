# New ports collection makefile for:	p5-Agent
# Date created:				04 Nov 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Agent
PORTVERSION=	3.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module that provides a foundation for software agent developers

BUILD_DEPENDS=	p5-Class-Tom>=0:${PORTSDIR}/devel/p5-Class-Tom
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Agent.3 Agent::Transport::TCP.3 \
		Agent::Transport.3 Agent::Message.3

.include <bsd.port.mk>
