# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Geo-GML
PORTVERSION=	0.17
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Module to Process Geography Markup Language

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Report>=0.18:devel/p5-Log-Report \
		p5-XML-Compile>=1.58:textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=1.05:textproc/p5-XML-Compile-Cache
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:devel/p5-Test-Pod

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
