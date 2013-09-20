# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IO-Prompt
PORTVERSION=	0.99.7002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/(\..+)\./\1/}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Interactively prompt for user input

BUILD_DEPENDS=	p5-version>0:${PORTSDIR}/devel/p5-version \
		p5-Term-ReadKey>0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-Want>0:${PORTSDIR}/devel/p5-Want
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	IO::Prompt.3

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

NO_STAGE=	yes
.include <bsd.port.mk>
