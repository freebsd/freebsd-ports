# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Regexp-Compare
PORTVERSION=	0.23
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Partial ordering for regular expressions

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USE_PERL5=	5.16+ configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502200
BROKEN=		Fails to build with Perl >= 5.22
.endif

.include <bsd.port.post.mk>
