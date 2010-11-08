# New ports collection makefile for:	p5-POE-Component-Server-IRC
# Date created:		2008-04-15
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-IRC
PORTVERSION=	1.42
CATEGORIES=	irc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	A fully event-driven networkable IRC server daemon module

BUILD_DEPENDS=	p5-Algorithm-Diff>=1.19:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-Crypt-PasswdMD5>=1.3:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-Net-Netmask>=1.9012:${PORTSDIR}/net-mgmt/p5-Net-Netmask \
		p5-POE>=0.9999:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-Client-DNS>=1:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
		p5-POE-Component-Client-Ident>=1:${PORTSDIR}/net/p5-POE-Component-Client-Ident \
		p5-POE-Component-IRC>=5.18:${PORTSDIR}/irc/p5-POE-Component-IRC \
		p5-Object-Pluggable>=1.27:${PORTSDIR}/devel/p5-Object-Pluggable \
		p5-POE-Filter-IRCD>=2.2:${PORTSDIR}/irc/p5-POE-Filter-IRCD
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		pmkpasswd.1
MAN3=		POE::Component::Server::IRC.3 \
		POE::Component::Server::IRC::OperServ.3 \
		POE::Component::Server::IRC::Common.3 \
		POE::Component::Server::IRC::Plugin.3 \
		POE::Component::Server::IRC::Backend.3

.include <bsd.port.mk>
