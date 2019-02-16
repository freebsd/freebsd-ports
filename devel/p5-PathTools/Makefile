# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PathTools
PORTVERSION=	3.7500
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XSAWYERX
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C|00$||}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl module for portably manipulating file specifications

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Cwd/Cwd.so

.include <bsd.port.mk>
