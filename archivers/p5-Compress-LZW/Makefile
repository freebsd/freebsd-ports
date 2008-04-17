# New ports collection makefile for:	p5-Compress-LZW
# Date created:		2006-07-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Compress-LZW
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure perl implementation of LZW

PERL_CONFIGURE=	yes

MAN3=		Compress::LZW.3

post-patch:
	${PERL} -pi -e 's/\@hattmoward/\\\@hattmoward/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
