# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	PerlIO-eol
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PerlIO layer for normalizing line endings

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PerlIO/eol/eol.so

.include <bsd.port.mk>
