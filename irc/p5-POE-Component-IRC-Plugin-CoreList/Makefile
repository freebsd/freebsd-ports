# New ports collection makefile for:	POE-Component-IRC-Plugin-Corelist
# Date created:	   31 may 2008
# Whom:		   Martin Wilke <miwi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IRC-Plugin-CoreList
PORTVERSION=	1.02
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A IRC plugin that provides CoreList goodness.

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Component/IRC.pm:${PORTSDIR}/irc/p5-POE-Component-IRC
RUN_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Component/IRC.pm:${PORTSDIR}/irc/p5-POE-Component-IRC

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
PERL_CONFIGURE=	yes

MAN3=		POE::Component::IRC::Plugin::CoreList.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
