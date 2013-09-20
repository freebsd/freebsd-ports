# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Data
PORTVERSION=	1.23
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BDFOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Test functions for particular variable types

RUN_DEPENDS=	p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Test::Data.3 \
		Test::Data::Array.3 \
		Test::Data::Function.3 \
		Test::Data::Hash.3 \
		Test::Data::Scalar.3

NO_STAGE=	yes
.include <bsd.port.mk>
