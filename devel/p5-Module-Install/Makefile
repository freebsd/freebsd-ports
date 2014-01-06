# Created by: clsung
# $FreeBSD$

PORTNAME=	Module-Install
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Standalone, extensible Perl module installer

BUILD_DEPENDS=	p5-File-Remove>=1.42:${PORTSDIR}/devel/p5-File-Remove \
		p5-JSON>=2.14:${PORTSDIR}/converters/p5-JSON \
		p5-Module-ScanDeps>=0.89:${PORTSDIR}/devel/p5-Module-ScanDeps \
		p5-PAR-Dist>=0.29:${PORTSDIR}/devel/p5-PAR-Dist \
		p5-YAML-Tiny>=1.38:${PORTSDIR}/textproc/p5-YAML-Tiny \
		p5-libwww>=5.812:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	--skip

.include <bsd.port.mk>
