# $FreeBSD$

PORTNAME=	IO-Handle-Util
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for working with IO::Handle like objects

RUN_DEPENDS=	\
	p5-IO-String>0:devel/p5-IO-String \
	p5-Sub-Exporter>0:devel/p5-Sub-Exporter \
	p5-asa>0:devel/p5-asa
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
