# New ports collection makefile for:	p5-Sub-Exporter-Progressive
# Date created:		2012-08-01
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sub-Exporter-Progressive
PORTVERSION=	0.001.004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Only use Sub::Exporter if you need it

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Sub::Exporter::Progressive.3

post-patch:
	@${REINPLACE_CMD} -e '/NAME/ s|Sub-Exporter-Progressive|Sub::Exporter::Progressive|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
