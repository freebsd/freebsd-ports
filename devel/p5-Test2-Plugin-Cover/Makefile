# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	Test2-Plugin-Cover
PORTVERSION=	0.000022
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and Minimal file coverage info

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Path-Tiny>=0.048:devel/p5-Path-Tiny
TEST_DEPENDS=	p5-Test2-Suite>=0.000130:devel/p5-Test2-Suite

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 503200
RUN_DEPENDS+=	p5-Test-Simple>=1.302166:devel/p5-Test-Simple
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Test2/Plugin/Cover/Cover.so

.include <bsd.port.post.mk>
