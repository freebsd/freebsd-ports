# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Eval-Context
PORTVERSION=	0.09.11
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NKH
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Evaluate Perl code in context wrapper

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Test-Output>=0:devel/p5-Test-Output \
		p5-Package-Generator>=0:devel/p5-Package-Generator \
		p5-Test-Spelling>=0:devel/p5-Test-Spelling \
		p5-Test-Block>=0:devel/p5-Test-Block \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings \
		p5-Test-Distribution>=0:devel/p5-Test-Distribution \
		p5-Test-Warn>=0:devel/p5-Test-Warn \
		p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Dependencies>=0:devel/p5-Test-Dependencies \
		p5-Test-Strict>=0:devel/p5-Test-Strict \
		p5-Directory-Scratch-Structured>=0:devel/p5-Directory-Scratch-Structured \
		p5-Data-TreeDumper>=0:devel/p5-Data-TreeDumper \
		p5-Data-Compare>=0:devel/p5-Data-Compare \
		p5-File-Slurp>=0:devel/p5-File-Slurp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
