# Created by: Ruben van Staveren
# $FreeBSD$

PORTNAME=	threads-shared
PORTVERSION=	1.59
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JDHEDDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Share data structures between threads

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/threads/shared/shared.so

.include <bsd.port.mk>
