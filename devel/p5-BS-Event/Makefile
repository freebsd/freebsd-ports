# New ports collection makefile for:	p5-BS-Event
# Date created:		2008-04-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	BS-Event
PORTVERSION=	0.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/E/EL/ELMEX
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A class that provides an event callback interface

PERL_CONFIGURE=	yes

MAN3=		BS::Event.3

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/samples/simple_example ${EXAMPLESDIR}/

.include <bsd.port.mk>
