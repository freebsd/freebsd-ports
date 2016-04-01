# Created by: Martin Wilke <miwi@FreeBSD.org
# $FreeBSD$

PORTNAME=	POE-Component-IRC-Plugin-Bollocks
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE::Component::IRC plugin that talks bollocks

BUILD_DEPENDS=	p5-Dev-Bollocks>=0.06:textproc/p5-Dev-Bollocks \
		p5-POE-Component-IRC>=0:irc/p5-POE-Component-IRC \
		p5-POE>=0:devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
USES=		perl5
USE_PERL5=	configure

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
