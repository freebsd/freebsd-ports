# Ports collection makefile for:	Astro-SIMBAD-Client
# Date created:			11 April, 2009
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Astro-SIMBAD-Client
PORTVERSION=	0.022
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An object-oriented interface to SIMBAD4

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Parser>=3.60:${PORTSDIR}/www/p5-HTML-Parser \
		p5-SOAP-Lite>0:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-DoubleEncodedEntities>=1.0:${PORTSDIR}/textproc/p5-XML-DoubleEncodedEntities
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	-y

MAN1=	simbadc.1
MAN3=	Astro::SIMBAD::Client.3

.include <bsd.port.mk>
