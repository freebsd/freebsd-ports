# $FreeBSD$

PORTNAME=	File-ShareDir-ProjectDistDir
PORTVERSION=	0.5.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for set-and-forget using a directory in projects root

RUN_DEPENDS=	\
	p5-File-ShareDir>0:${PORTSDIR}/devel/p5-File-ShareDir \
	p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
	p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple

USES=	perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
