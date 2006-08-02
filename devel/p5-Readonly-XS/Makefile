# New ports collection makefile for:	p5-Readonly-XS
# Date created:		2 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Readonly-XS
DISTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Speed up read-only scalar variables

BUILD_DEPENDS=	p5-Readonly>=1.02:${PORTSDIR}/devel/p5-Readonly
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		${PORTNAME:S/-/::/g}.3

.include <bsd.port.mk>
