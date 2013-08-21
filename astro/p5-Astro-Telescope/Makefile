# New ports collection makefile for:	p5-Astro-Telescope
# Date created:		2012-07-01
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Astro-Telescope
PORTVERSION=	0.71
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Class for obtaining telescope information

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Astro-PAL>=0.99:${PORTSDIR}/astro/p5-Astro-PAL
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	modbuild
USES=		perl5

MAN3=		Astro::Telescope.3

.include <bsd.port.mk>
