# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	CPAN-Meta
PORTVERSION=	2.150010
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Distribution metadata for a CPAN dist

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
BUILD_DEPENDS+=	p5-JSON-PP>=2.27300:converters/p5-JSON-PP
RUN_DEPENDS+=	p5-JSON-PP>=2.27300:converters/p5-JSON-PP
.endif

.include <bsd.port.post.mk>
