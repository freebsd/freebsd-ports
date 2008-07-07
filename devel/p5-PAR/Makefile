# New ports collection makefile for:	devel/p5-PAR
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	PAR
PORTVERSION=	0.98.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9])$/\1/}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Perl Archive Toolkit

BUILD_DEPENDS=	p5-Archive-Zip>=1.00:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-AutoLoader>=5.63:${PORTSDIR}/devel/p5-AutoLoader \
		p5-Compress-Zlib>=1.30:${PORTSDIR}/archivers/p5-Compress-Zlib \
		p5-PAR-Dist>=0.22:${PORTSDIR}/devel/p5-PAR-Dist
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		PAR.3 \
		PAR::Environment.3 \
		PAR::FAQ.3 \
		PAR::Heavy.3 PAR::Tutorial.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

.include <bsd.port.post.mk>
