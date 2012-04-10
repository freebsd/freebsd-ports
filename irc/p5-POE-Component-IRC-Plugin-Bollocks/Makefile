# New ports collection makefile for:	POE-Component-IRC-Plugin-Bollocks
# Date created:	   31 may 2008
# Whom:		   Martin Wilke <miwi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IRC-Plugin-Bollocks
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	irc perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A POE::Component::IRC plugin that talks bollocks

BUILD_DEPENDS=	p5-Dev-Bollocks>=0.06:${PORTSDIR}/textproc/p5-Dev-Bollocks \
		p5-POE-Component-IRC>=0:${PORTSDIR}/irc/p5-POE-Component-IRC \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
PERL_CONFIGURE=	yes

MAN3=		POE::Component::IRC::Plugin::Bollocks.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
