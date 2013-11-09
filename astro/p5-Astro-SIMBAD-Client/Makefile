# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Astro-SIMBAD-Client
PORTVERSION=	0.028
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:WYANT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OO interface to SIMBAD4

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-DoubleEncodedEntities>=1:${PORTSDIR}/textproc/p5-XML-DoubleEncodedEntities \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	-y

.include <bsd.port.mk>
