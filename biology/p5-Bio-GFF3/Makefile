# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Bio-GFF3
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fast low-level functions for parsing and formatting GFF3

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-ReadBackwards>=0:devel/p5-File-ReadBackwards \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-String>=0:devel/p5-IO-String

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
