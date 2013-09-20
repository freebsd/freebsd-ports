# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-Find-Rule-Perl
PORTVERSION=	1.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Common rules for searching for Perl things

BUILD_DEPENDS=	p5-File-Find-Rule>=0.20:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-Parse-CPAN-Meta>=1.38:${PORTSDIR}/devel/p5-Parse-CPAN-Meta \
		p5-Params-Util>=0.38:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	File::Find::Rule::Perl.3

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

NO_STAGE=	yes
.include <bsd.port.mk>
