# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	List-MoreUtils
DISTVERSION=	0.416
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide the stuff missing in List::Util

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Exporter-Tiny>=0.038:devel/p5-Exporter-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502401
BUILD_DEPENDS+=	p5-XSLoader>=0.22:devel/p5-XSLoader
RUN_DEPENDS+=	p5-XSLoader>=0.22:devel/p5-XSLoader
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/List/MoreUtils/MoreUtils.so

.include <bsd.port.post.mk>
