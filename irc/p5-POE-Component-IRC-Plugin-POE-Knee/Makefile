# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-IRC-Plugin-POE-Knee
PORTVERSION=	1.08
PORTREVISION=	1
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A POE::Component::IRC plugin that runs Acme::POE::Knee races

BUILD_DEPENDS=	p5-Math-Random>=0.69:${PORTSDIR}/math/p5-Math-Random \
		p5-POE-Component-IRC>=0:${PORTSDIR}/irc/p5-POE-Component-IRC \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
USES=		perl5
USE_PERL5=	configure

MAN3=		POE::Component::IRC::Plugin::POE::Knee.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
