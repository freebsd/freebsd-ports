# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Parse-IRC
PORTVERSION=	1.20
CATEGORIES=	irc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Parser for the IRC protocol

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

MAN3=		Parse::IRC.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.59:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
.endif

.include <bsd.port.post.mk>
