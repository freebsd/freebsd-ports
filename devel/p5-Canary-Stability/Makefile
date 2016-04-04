# $FreeBSD$

PORTNAME=	Canary-Stability
PORTVERSION=	2011
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MLEHMANN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Checks what version of perl you're running

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	ACTIVATE
ACTIVATE_DESC=	Enable Canary::Stability functionality

# Just skip everything in this module unless activated
post-patch-ACTIVATE-off:
	@${REINPLACE_CMD} -e '/^sub import {/s/$$/ return 1; /' \
		${WRKSRC}/Stability.pm

.include <bsd.port.mk>
