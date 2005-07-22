# ex:ts=8
# New ports collection makefile for:	POE::Component::IRC
# Date created:		Aug 19, 2001
# Whom:			ijliao
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IRC
PORTVERSION=	4.65
CATEGORIES=	irc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	apeiron+ports@coitusmentis.info
COMMENT=	A fully event-driven IRC client module

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::IRC.3 \
		POE::Component::IRC::Constants.3 \
		POE::Component::IRC::Plugin.3 \
		POE::Component::IRC::Plugin::BotAddressed.3 \
		POE::Component::IRC::Plugin::BotTraffic.3 \
		POE::Component::IRC::Plugin::Connector.3 \
		POE::Component::IRC::Plugin::Whois.3 \
		POE::Component::IRC::Qnet.3 \
		POE::Component::IRC::Qnet::State.3 \
		POE::Component::IRC::State.3 \
		POE::Component::IRC::Test::Harness.3 \
		POE::Filter::CTCP.3 \
		POE::Filter::IRC.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
