# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Compress-LZW
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure perl implementation of LZW

USES=		perl5
USE_PERL5=	configure

MAN3=		Compress::LZW.3

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|\@hattmoward|\\@hattmoward|' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
