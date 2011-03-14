# Ports collection makefile for:	Astro-SIMBAD-Client
# Date created:			11 April, 2009
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Astro-SIMBAD-Client
PORTVERSION=	0.019
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	An object-oriented interface to SIMBAD4

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Parser>=3.60:${PORTSDIR}/www/p5-HTML-Parser \
		p5-SOAP-Lite>0:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-DoubleEncodedEntities>=1.0:${PORTSDIR}/textproc/p5-XML-DoubleEncodedEntities

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	-y

MAN1=	simbadc.1
MAN3=	Astro::SIMBAD::Client.3

.include <bsd.port.mk>
