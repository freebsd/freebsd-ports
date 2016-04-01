# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CPAN-Changes
PORTVERSION=	0.40.0001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read and write CPAN Changes files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-version>=0.99.06:devel/p5-version
RUN_DEPENDS+=	p5-version>=0.99.06:devel/p5-version
.endif

.include <bsd.port.post.mk>
