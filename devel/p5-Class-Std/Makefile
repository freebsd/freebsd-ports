# New ports collection makefile for:	p5-Class-Std
# Date created:		30 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Std
DISTVERSION=	0.0.9
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Support for creating standard "inside-out" classes

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Class::Std.3

.include <bsd.port.mk>
