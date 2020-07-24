# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	ExtUtils-MakeMaker
PORTVERSION=	7.46
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Designed to write a Makefile for an extension module

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

CONFLICTS_INSTALL=	p5-ExtUtils-Command

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/d; /my::bundles/d' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e '/^bundled\//d' ${WRKSRC}/MANIFEST
	@${RM} -r ${WRKSRC}/bundled/

.include <bsd.port.mk>
