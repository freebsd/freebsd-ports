# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	constant-lexical
PORTVERSION=	2.0003
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/constant CPAN
MASTER_SITE_SUBDIR=	CPAN:SPROUT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl pragma to declare lexical compile-time constants

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Lexical-Var>=0:devel/p5-Lexical-Var \
		p5-Sub-Delete>=0:devel/p5-Sub-Delete

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/constant/lexical/lexical.so

.include <bsd.port.mk>
