# New ports collection makefile for:	p5-POE-Filter-Zlib
# Date created:		2006-07-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-Zlib
PORTVERSION=	2.0.2
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE filter wrapped around Compress::Zlib

RUN_DEPENDS=	p5-POE>=0.38:${PORTSDIR}/devel/p5-POE
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Filter::Zlib.3 \
    		POE::Filter::Zlib::Stream.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-Compress-Zlib>=1.34:${PORTSDIR}/archivers/p5-Compress-Zlib
.endif

.include <bsd.port.post.mk>
