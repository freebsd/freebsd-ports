# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Alias
PORTVERSION=	1.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Comprehensive set of aliasing operations

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Data/Alias/Alias.so

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502501
BROKEN=		Does not build, op_sibling usage. https://rt.cpan.org/Public/Bug/Display.html?id=114544
.endif

.include <bsd.port.post.mk>
