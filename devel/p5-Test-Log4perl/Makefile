# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Log4perl
PORTVERSION=	0.1001
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test::Log4perl - test Log::Log4perl

BUILD_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Lingua-EN-Numbers-Ordinate>=0:textproc/p5-Lingua-EN-Numbers-Ordinate \
		p5-Class-Accessor-Chained>=0:devel/p5-Class-Accessor-Chained \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
