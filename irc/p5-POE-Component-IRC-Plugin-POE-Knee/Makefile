# New ports collection makefile for:	POE-Component-IRC-Plugin-POE-Knee
# Date created:	   31 may 2008
# Whom:		   Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IRC-Plugin-POE-Knee
PORTVERSION=	1.08
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A POE::Component::IRC plugin that runs Acme::POE::Knee races

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Component/IRC.pm:${PORTSDIR}/irc/p5-POE-Component-IRC
RUN_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Component/IRC.pm:${PORTSDIR}/irc/p5-POE-Component-IRC

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
PERL_CONFIGURE=	yes

MAN3=		POE::Component::IRC::Plugin::POE::Knee.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
