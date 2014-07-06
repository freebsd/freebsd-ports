# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	BS-Event
PORTVERSION=	0.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ELMEX
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Class that provides an event callback interface

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	EXAMPLES

USE_PERL5=	configure
USES=		perl5

PORTEXAMPLES=	simple_example

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/samples/simple_example ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
