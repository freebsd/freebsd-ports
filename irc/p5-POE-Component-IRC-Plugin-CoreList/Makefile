# Created by: Martin Wilke <miwi@FreeBSD.org
# $FreeBSD$

PORTNAME=	POE-Component-IRC-Plugin-CoreList
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	IRC plugin that provides CoreList goodness

BUILD_DEPENDS=	p5-POE>=0:devel/p5-POE \
		p5-POE-Component-IRC>=0:irc/p5-POE-Component-IRC
RUN_DEPENDS=	p5-POE>=0:devel/p5-POE \
		p5-POE-Component-IRC>=0:irc/p5-POE-Component-IRC

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
USES=		perl5
USE_PERL5=	configure

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
