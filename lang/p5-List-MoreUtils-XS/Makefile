# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	List-MoreUtils-XS
PORTVERSION=	0.423
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide compiled List::MoreUtils functions

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502503
BUILD_DEPENDS+=	p5-XSLoader>=0.22:devel/p5-XSLoader
RUN_DEPENDS+=	p5-XSLoader>=0.22:devel/p5-XSLoader
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/List/MoreUtils/XS/XS.so

.include <bsd.port.post.mk>
