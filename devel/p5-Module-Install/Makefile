# Created by: clsung
# $FreeBSD$

PORTNAME=	Module-Install
PORTVERSION=	1.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Standalone, extensible Perl module installer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Remove>=1.42:devel/p5-File-Remove \
		p5-JSON>=2.14:converters/p5-JSON \
		p5-Module-ScanDeps>=1.09:devel/p5-Module-ScanDeps \
		p5-PAR-Dist>=0.29:devel/p5-PAR-Dist \
		p5-YAML-Tiny>=1.38:textproc/p5-YAML-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	--skip

.include <bsd.port.mk>
