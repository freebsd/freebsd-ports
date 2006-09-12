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
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Compress
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure perl implementation of LZW

PERL_CONFIGURE=	yes

MAN3=		Compress::LZW.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

post-patch:
	${PERL} -pi -e 's/\@hattmoward/\\\@hattmoward/' ${WRKSRC}/Makefile.PL
.if ${PERL_LEVEL} < 500600
	${REINPLACE_CMD} -e '/warnings/d' ${WRKSRC}/*
.endif

.include <bsd.port.post.mk>
