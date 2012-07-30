# New ports collection makefile for:	p5-Safe-Isa
# Date created:		2012-07-30
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Safe-Isa
PORTVERSION=	1.000.002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Call isa, can, does and DOES safely on things that may not be objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

MAN3=		Safe::Isa.3

post-patch:
	@${REINPLACE_CMD} -e '/NAME/ s|Safe-Isa|Safe::Isa|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
