# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-TempDir-Tiny
PORTVERSION=	0.018
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Temporary directories that stick around when tests fail

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 503000
BUILD_DEPENDS+=	p5-File-Temp>=0.2308:devel/p5-File-Temp
RUN_DEPENDS+=	p5-File-Temp>=0.2308:devel/p5-File-Temp
.endif

.include <bsd.port.post.mk>
