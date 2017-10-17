# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Bot-BasicBot
PORTVERSION=	0.91
CATEGORIES=	irc perl5
MASTER_SITES=	CPAN/Bot
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple irc bot baseclass

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-POE>=0:devel/p5-POE \
		p5-POE-Component-IRC>=0:irc/p5-POE-Component-IRC
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
