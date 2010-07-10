# ex:ts=8
# New ports collection makefile for:	POE::Component::IRC
# Date created:		Aug 19, 2001
# Whom:			ijliao
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IRC
PORTVERSION=	6.35
CATEGORIES=	irc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A fully event-driven IRC client module

RUN_DEPENDS=	p5-POE>=0.3202:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-Pluggable>=1.24:${PORTSDIR}/devel/p5-POE-Component-Pluggable \
		p5-POE-Filter-IRCD>=1.7:${PORTSDIR}/irc/p5-POE-Filter-IRCD \
		p5-POE-Component-Client-DNS>=0.99:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
		p5-POE-Component-SSLify>0:${PORTSDIR}/security/p5-POE-Component-SSLify
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

PORTEXAMPLES=	*

MAN3=		POE::Component::IRC.3 \
		POE::Component::IRC::Common.3 \
		POE::Component::IRC::Constants.3 \
		POE::Component::IRC::Plugin.3 \
		POE::Component::IRC::Plugin::AutoJoin.3 \
		POE::Component::IRC::Plugin::BotAddressed.3 \
		POE::Component::IRC::Plugin::BotTraffic.3 \
		POE::Component::IRC::Plugin::DCC.3 \
		POE::Component::IRC::Plugin::CTCP.3 \
		POE::Component::IRC::Plugin::Connector.3 \
		POE::Component::IRC::Plugin::Console.3 \
		POE::Component::IRC::Plugin::CycleEmpty.3 \
		POE::Component::IRC::Plugin::FollowTail.3 \
		POE::Component::IRC::Plugin::ISupport.3 \
		POE::Component::IRC::Plugin::Logger.3 \
		POE::Component::IRC::Plugin::NickReclaim.3 \
		POE::Component::IRC::Plugin::NickServID.3 \
		POE::Component::IRC::Plugin::PlugMan.3 \
		POE::Component::IRC::Plugin::Proxy.3 \
		POE::Component::IRC::Plugin::Whois.3 \
		POE::Component::IRC::Projects.3 \
		POE::Component::IRC::Qnet.3 \
		POE::Component::IRC::Qnet::State.3 \
		POE::Component::IRC::State.3 \
		POE::Component::IRC::Cookbook::Reload.3 \
		POE::Component::IRC::Cookbook::Seen.3 \
		POE::Component::IRC::Cookbook::Translator.3 \
		POE::Component::IRC::Cookbook::Disconnecting.3 \
		POE::Component::IRC::Cookbook::BasicBot.3 \
		POE::Component::IRC::Cookbook::Gtk2.3 \
		POE::Component::IRC::Cookbook.3 \
		POE::Component::IRC::Cookbook::Resolver.3 \
		POE::Component::IRC::Cookbook::Hailo.3 \
		POE::Component::IRC::Plugin::BotCommand.3 \
		POE::Filter::IRC.3 \
		POE::Filter::IRC::Compat.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
