# Created by: chinsan
# $FreeBSD$

PORTNAME=	Variable-Magic
PORTVERSION=	0.60
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Associate user-defined magic to variables from Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Variable/Magic/Magic.so

.include <bsd.port.mk>
