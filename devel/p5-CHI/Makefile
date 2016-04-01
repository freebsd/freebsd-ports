# $FreeBSD$

PORTNAME=	CHI
PORTVERSION=	0.580
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HAARG
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.58

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for unified cache interface

BUILD_DEPENDS:=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Carp-Assert>=0.20:devel/p5-Carp-Assert \
	p5-Data-UUID>0:devel/p5-Data-UUID \
	p5-Digest-JHash>0:security/p5-Digest-JHash \
	p5-Hash-MoreUtils>0:devel/p5-Hash-MoreUtils \
	p5-JSON>0:converters/p5-JSON \
	p5-List-MoreUtils>=0.13:lang/p5-List-MoreUtils \
	p5-Log-Any>=0.08:devel/p5-Log-Any \
	p5-Moo>=1.003:devel/p5-Moo \
	p5-MooX-Types-MooseLike>=0.23:devel/p5-MooX-Types-MooseLike \
	p5-MooX-Types-MooseLike-Numeric>0:devel/p5-MooX-Types-MooseLike-Numeric \
	p5-String-RewritePrefix>0:textproc/p5-String-RewritePrefix \
	p5-Task-Weaken>0:devel/p5-Task-Weaken \
	p5-Time-Duration>=1.06:devel/p5-Time-Duration \
	p5-Time-Duration-Parse>=0.03:devel/p5-Time-Duration-Parse \
	p5-Try-Tiny>=0.05:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Warn>=0:devel/p5-Test-Warn \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Class>=0:devel/p5-Test-Class \
		p5-TimeDate>=0:devel/p5-TimeDate

USES=	perl5
USE_PERL5=	configure

.include <bsd.port.mk>
