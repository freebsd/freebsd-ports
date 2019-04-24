# $FreeBSD$

PORTNAME=	Canary-Stability
PORTVERSION=	2013
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MLEHMANN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Checks what version of perl you're running and then complains about it #'

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	ACTIVATE
ACTIVATE_DESC=	Enable Canary::Stability functionality

# Install an empty stub
post-patch-ACTIVATE-off:
	@${CP} ${FILESDIR}/Stability.pm ${WRKSRC}

.include <bsd.port.mk>
