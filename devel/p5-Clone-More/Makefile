# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Clone-More
PORTVERSION=	0.90.2
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl module for natively copying Perl data structures

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USE_PERL5=	configure
USES=		perl5
WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Clone/More/More.so

.include <bsd.port.mk>
