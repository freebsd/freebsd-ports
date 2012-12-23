# New ports collection makefile for:	devel/p5-PAR
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	PAR
PORTVERSION=	1.00.7
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9])$/\1/}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Perl Archive Toolkit

RUN_DEPENDS=	p5-Archive-Zip>=1.00:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-AutoLoader>=5.67:${PORTSDIR}/devel/p5-AutoLoader \
		p5-PAR-Dist>=0.32:${PORTSDIR}/devel/p5-PAR-Dist
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		PAR.3 \
		PAR::Environment.3 \
		PAR::FAQ.3 \
		PAR::Heavy.3 PAR::Tutorial.3 \
		PAR::SetupProgname.3 \
		PAR::SetupTemp.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>
