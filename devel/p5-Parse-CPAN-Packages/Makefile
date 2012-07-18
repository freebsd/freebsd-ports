# New ports collection makefile for:	devel/p5-Parse-CPAN-Packages
# Date created:				Mar 27 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Parse-CPAN-Packages
PORTVERSION=	2.36
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

PERL_CONFIGURE=	yes

MAN3=	Parse::CPAN::Packages.3 \
	Parse::CPAN::Packages::Distribution.3 \
	Parse::CPAN::Packages::Package.3

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
