# ex:ts=8
# Ports collection makefile for:	Inline::Files
# Date created:			Jun 5, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Inline-Files
PORTVERSION=	0.62
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Multiple virtual files at the end of your code

BUILD_DEPENDS=	p5-Filter>=0:${PORTSDIR}/devel/p5-Filter
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Inline::Files.3 \
	Inline::Files::Virtual.3

.include <bsd.port.mk>
