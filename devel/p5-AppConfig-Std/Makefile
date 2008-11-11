# New ports collection makefile for:   p5-AppConfig-Std
# Date created:                20 July 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	AppConfig-Std
PORTVERSION=	1.07
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A subclass of AppConfig that provides standard options

RUN_DEPENDS=	p5-AppConfig>=1.52:${PORTSDIR}/devel/p5-AppConfig
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		AppConfig::Std.3

.include <bsd.port.mk>
