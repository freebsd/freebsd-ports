# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Parse-CPAN-Packages
PORTVERSION=	2.40
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse 02packages.details.txt.gz from CPAN

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Peek>0:archivers/p5-Archive-Peek \
		p5-CPAN-DistnameInfo>0:devel/p5-CPAN-DistnameInfo \
		p5-Moo>=0:devel/p5-Moo \
		p5-PPI>0:textproc/p5-PPI \
		p5-Type-Tiny>0:devel/p5-Type-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-InDistDir>0:devel/p5-Test-InDistDir \
		p5-File-Slurp>0:devel/p5-File-Slurp

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
