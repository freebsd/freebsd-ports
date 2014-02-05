# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PAR-Packer
PORTVERSION=	1.01.4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9])$/\1/}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	PAR Packager

RUN_DEPENDS=	p5-Archive-Zip>=1.00:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress \
		p5-Getopt-ArgvFile>=1.07:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-Module-ScanDeps>=1.09:${PORTSDIR}/devel/p5-Module-ScanDeps \
		p5-Module-Signature>=0:${PORTSDIR}/security/p5-Module-Signature \
		p5-PAR-Dist>=0.22:${PORTSDIR}/devel/p5-PAR-Dist \
		p5-PAR>=1.00.5:${PORTSDIR}/devel/p5-PAR \
		p5-B-Deobfuscate>=0:${PORTSDIR}/devel/p5-B-Deobfuscate
BUILD_DEPENDS:=	${RUN_DEPENDS}

CONFLICTS=	sketchy-*

USES=		perl5
USE_PERL5=	configure
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
