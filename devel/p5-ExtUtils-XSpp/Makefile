# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	ExtUtils-XSpp
PORTVERSION=	0.16.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	XS for C++ in Perl

BUILD_DEPENDS=	p5-Test-Base>=0:${PORTSDIR}/devel/p5-Test-Base \
		p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501301
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=2.22.02:${PORTSDIR}/devel/p5-ExtUtils-ParseXS
.endif

.include <bsd.port.post.mk>
