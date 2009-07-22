# New ports collection makefile for:	devel/p5-PAR
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	PAR
PORTVERSION=	0.99.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9])$/\1/}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Perl Archive Toolkit

BUILD_DEPENDS=	p5-Archive-Zip>=1.00:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-AutoLoader>=5.67:${PORTSDIR}/devel/p5-AutoLoader \
		p5-Compress-Zlib>=1.30:${PORTSDIR}/archivers/p5-Compress-Zlib \
		p5-PAR-Dist>=0.32:${PORTSDIR}/devel/p5-PAR-Dist
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		PAR.3 \
		PAR::Environment.3 \
		PAR::FAQ.3 \
		PAR::Heavy.3 PAR::Tutorial.3 \
		PAR::SetupProgname.3 \
		PAR::SetupTemp.3

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
