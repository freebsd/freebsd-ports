# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Inline-C
PORTVERSION=	0.78
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write Perl Subroutines in C

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Inline>=0.79:devel/p5-Inline \
		p5-Parse-RecDescent>=1.967.009:devel/p5-Parse-RecDescent \
		p5-Pegex>=0.58:devel/p5-Pegex
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-Test-Warn>=0.23:devel/p5-Test-Warn \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML
BUILD_DEPENDS+=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install

CONFLICTS_INSTALL=	p5-Inline-0.[0-5]*

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
