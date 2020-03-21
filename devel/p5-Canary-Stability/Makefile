# $FreeBSD$

PORTNAME=	Canary-Stability
PORTVERSION=	2013
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	# none
PKGNAMEPREFIX=	p5-
DISTFILES=	# none

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Stub for ancient system-checking module

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5

NO_ARCH=	yes
NO_BUILD=	yes

# Install empty stub
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Canary
	${INSTALL_DATA} ${FILESDIR}/Stability.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Canary

.include <bsd.port.mk>
