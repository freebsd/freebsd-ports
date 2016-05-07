# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Path-Resource
PORTVERSION=	0.072
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RKRIMEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl module for combining local path manipulation and URI manipulation

BUILD_DEPENDS=	p5-Path-Abstract>0:devel/p5-Path-Abstract \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-URI>=0:net/p5-URI \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor
RUN_DEPENDS=	p5-Path-Abstract>0:devel/p5-Path-Abstract \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-URI>=0:net/p5-URI \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor
TEST_DEPENDS=	p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Test-Lazy>=0:devel/p5-Test-Lazy

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
