# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Parse-CPAN-Packages
PORTVERSION=	2.38
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse 02packages.details.txt.gz from CPAN

BUILD_DEPENDS=	p5-Archive-Peek>0:${PORTSDIR}/archivers/p5-Archive-Peek \
		p5-CPAN-DistnameInfo>0:${PORTSDIR}/devel/p5-CPAN-DistnameInfo \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-PPI>0:${PORTSDIR}/textproc/p5-PPI \
		p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-InDistDir>0:${PORTSDIR}/devel/p5-Test-InDistDir \
		p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp

USES=		perl5
USE_PERL5=	configure

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
