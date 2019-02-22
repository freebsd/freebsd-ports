# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-CheckManifest
PORTVERSION=	1.42
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Check if your Manifest matches your distro

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502902
BUILD_DEPENDS+=	p5-PathTools>=3.7500:devel/p5-PathTools
RUN_DEPENDS+=	p5-PathTools>=3.7500:devel/p5-PathTools
.endif

.include <bsd.port.post.mk>
