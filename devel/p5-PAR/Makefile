# New ports collection makefile for:	devel/p5-PAR
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	PAR
PORTVERSION=	0.97.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PAR
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9])$/\1/}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Perl Archive Toolkit

BUILD_DEPENDS=	p5-Archive-Zip>=1.00:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-AutoLoader>=5.62:${PORTSDIR}/devel/p5-AutoLoader \
		p5-Compress-Zlib>=1.30:${PORTSDIR}/archivers/p5-Compress-Zlib \
		p5-PAR-Dist>=0.21:${PORTSDIR}/devel/p5-PAR-Dist
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

.if ${PERL_LEVEL} < 500601
IGNORE=		only supports the ports versions of Perl,
IGNORE+=If you have installed a Perl port, and are getting this message,
IGNORE+=please make sure you have given the command \'use.perl port\'
.endif # ${PERL_LEVEL} < 500601

.include <bsd.port.post.mk>
