# New ports collection makefile for:	p5-Encode-Detect
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Encode-Detect
PORTVERSION=	1.00
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Encode
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An Encode::Encoding subclass that detects the encoding of data

BUILD_DEPENDS+=	${SITE_PERL}/ExtUtils/CBuilder.pm:${PORTSDIR}/devel/p5-ExtUtils-CBuilder

PERL_MODBUILD=	yes

MAN3=		Encode::Detect.3 Encode::Detect::Detector.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Encode.pm:${PORTSDIR}/converters/p5-Encode
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Encode.pm:${PORTSDIR}/converters/p5-Encode
.endif

.include <bsd.port.post.mk>
