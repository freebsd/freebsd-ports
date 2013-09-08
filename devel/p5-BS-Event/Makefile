# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	BS-Event
PORTVERSION=	0.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ELMEX
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A class that provides an event callback interface

USES=		perl5
USE_PERL5=	configure

MAN3=		BS::Event.3

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/samples/simple_example ${EXAMPLESDIR}/

.include <bsd.port.mk>
