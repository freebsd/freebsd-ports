# ex:ts=8
# New ports collection makefile for:	POE::Component::IRC
# Date created:		Aug 19, 2001
# Whom:			ijliao
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IRC
PORTVERSION=	4.96
CATEGORIES=	irc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	A fully event-driven IRC client module

BUILD_DEPENDS=	p5-POE>=0.3202:${PORTSDIR}/devel/p5-POE \
		p5-POE-Filter-IRCD>=1.7:${PORTSDIR}/irc/p5-POE-Filter-IRCD \
		${SITE_PERL}/POE/Component/Client/DNS.pm:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
		${SITE_PERL}/POE/Component/Client/Ident.pm:${PORTSDIR}/net/p5-POE-Component-Client-Ident \
		${SITE_PERL}/POE/Component/SSLify.pm:${PORTSDIR}/security/p5-POE-Component-SSLify
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::IRC.3 \
		POE::Component::IRC::Common.3 \
		POE::Component::IRC::Constants.3 \
		POE::Component::IRC::Pipeline.3 \
		POE::Component::IRC::Plugin.3 \
		POE::Component::IRC::Plugin::BotAddressed.3 \
		POE::Component::IRC::Plugin::BotTraffic.3 \
		POE::Component::IRC::Plugin::CTCP.3 \
		POE::Component::IRC::Plugin::Connector.3 \
		POE::Component::IRC::Plugin::Console.3 \
		POE::Component::IRC::Plugin::ISupport.3 \
		POE::Component::IRC::Plugin::NickReclaim.3 \
		POE::Component::IRC::Plugin::PlugMan.3 \
		POE::Component::IRC::Plugin::Proxy.3 \
		POE::Component::IRC::Plugin::Whois.3 \
		POE::Component::IRC::Projects.3 \
		POE::Component::IRC::Qnet.3 \
		POE::Component::IRC::Qnet::State.3 \
		POE::Component::IRC::State.3 \
		POE::Component::IRC::Test::Harness.3 \
		POE::Filter::CTCP.3 \
		POE::Filter::IRC.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing examples for ${PKGNAME}"
	@${INSTALL} -d ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}/
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600 #inherited from warnings
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
