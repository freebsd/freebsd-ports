# Ports collection makefile for:	Astro-SIMBAD-Client
# Date created:			11 April, 2009
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Astro-SIMBAD-Client
PORTVERSION=	0.025
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:WYANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An object-oriented interface to SIMBAD4

BUILD_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-DoubleEncodedEntities>=1:${PORTSDIR}/textproc/p5-XML-DoubleEncodedEntities \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	-y

MAN1=		simbadc.1
MAN3=		Astro::SIMBAD::Client.3

.include <bsd.port.mk>
