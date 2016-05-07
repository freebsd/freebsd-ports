# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Test-TAP-HTMLMatrix
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Creates colorful matrix of Test::Harness test run results

BUILD_DEPENDS=	p5-Test-TAP-Model>=0:devel/p5-Test-TAP-Model \
		p5-Petal>=0:textproc/p5-Petal \
		p5-Petal-Utils>=0:textproc/p5-Petal-Utils \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	${RM} ${WRKSRC}/example.pl

.include <bsd.port.mk>
