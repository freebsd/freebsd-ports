# New ports collection makefile for:	p5-Class-Field
# Date created:		1 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Field
DISTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Class Field Accessor Generator

PERL_CONFIGURE=	YES

MAN3=		Class::Field.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
BUILD_DEPENDS+=	p5-Encode>=0:${PORTSDIR}/converters/p5-Encode
RUN_DEPENDS+=	p5-Encode>=0:${PORTSDIR}/converters/p5-Encode
.endif

.include <bsd.port.post.mk>
