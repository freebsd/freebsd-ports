# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	String-TT
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl interface to interpolate lexical variables

RUN_DEPENDS=	p5-PadWalker>=1:devel/p5-PadWalker \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Template-Toolkit>=2:www/p5-Template-Toolkit \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-TableDriven>=0:devel/p5-Test-TableDriven
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
