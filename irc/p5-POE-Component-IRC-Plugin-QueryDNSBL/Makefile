# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-IRC-Plugin-QueryDNSBL
PORTVERSION=	1.04
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A POE::Component::IRC plugin for IRC based DNSBL queries

BUILD_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-IRC>=6.68:${PORTSDIR}/irc/p5-POE-Component-IRC \
		p5-POE-Component-Client-DNSBL>=0.06:${PORTSDIR}/dns/p5-POE-Component-Client-DNSBL \
		p5-Net-IP>=1.25:${PORTSDIR}/net-mgmt/p5-Net-IP
RUN_DEPENDS:=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-IRC>=6.68:${PORTSDIR}/irc/p5-POE-Component-IRC \
		p5-POE-Component-Client-DNSBL>=0.06:${PORTSDIR}/dns/p5-POE-Component-Client-DNSBL \
		p5-Net-IP>=1.25:${PORTSDIR}/net-mgmt/p5-Net-IP

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	examples/*.pl
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
