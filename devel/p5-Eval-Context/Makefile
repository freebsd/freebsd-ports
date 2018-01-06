# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Eval-Context
PORTVERSION=	0.09.11
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NKH
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Evaluate Perl code in context wrapper

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Package-Generator>=0:devel/p5-Package-Generator \
		p5-Directory-Scratch-Structured>=0:devel/p5-Directory-Scratch-Structured \
		p5-Data-TreeDumper>=0:devel/p5-Data-TreeDumper \
		p5-Data-Compare>=0:devel/p5-Data-Compare \
		p5-File-Slurp>=0:devel/p5-File-Slurp
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings \
		p5-Test-Output>=0:devel/p5-Test-Output \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

.include <bsd.port.mk>
