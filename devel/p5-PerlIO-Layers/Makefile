# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PerlIO-Layers
PORTVERSION=	0.011
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Query the properties/capabilities of filehandle

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USE_PERL5=	modbuild
USES=		perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PerlIO/Layers/Layers.so

.include <bsd.port.mk>
