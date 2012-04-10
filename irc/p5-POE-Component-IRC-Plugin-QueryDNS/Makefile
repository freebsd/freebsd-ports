# New ports collection makefile for:	p5-POE-Component-IRC-Plugin-QueryDNS
# Date created:	   20.06.2008
# Whom:		   Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IRC-Plugin-QueryDNS
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A POE::Component::IRC plugin for IRC based DNS queries

BUILD_DEPENDS=	p5-Net-IP>=1.25:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-POE-Component-Client-DNS>=1.00:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
		p5-POE-Component-IRC>=0:${PORTSDIR}/irc/p5-POE-Component-IRC
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
PERL_CONFIGURE=	yes

MAN3=		POE::Component::IRC::Plugin::QueryDNS.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
