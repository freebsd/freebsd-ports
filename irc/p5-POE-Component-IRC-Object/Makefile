# New ports collection makefile for:	POE-Component-IRC-Object
# Date created:	   05 July 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IRC-Object
PORTVERSION=	0.02
CATEGORIES=	irc perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A slightly simpler OO interface to POE::Component::IRC

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Component/IRC.pm:${PORTSDIR}/irc/p5-POE-Component-IRC
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
PERL_CONFIGURE=	yes

MAN3=		POE::Component::IRC::Object.3

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/example/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
