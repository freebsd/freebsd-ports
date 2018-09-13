# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Directory-Scratch
PORTVERSION=	0.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy-to-use self-cleaning scratch space

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Path-Tiny>=0.060:devel/p5-Path-Tiny \
		p5-String-Random>=0:devel/p5-String-Random

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
