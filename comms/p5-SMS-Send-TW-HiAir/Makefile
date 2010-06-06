# New ports collection makefile for:	p5-SMS-Send-TW-HiAir
# Date created:		2010-01-06
# Whom:			Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	SMS-Send-TW-HiAir
PORTVERSION=	0.02
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	SMS::Send driver for http://hiair.hinet.net/

RUN_DEPENDS=	p5-SMS-Send>=0:${PORTSDIR}/comms/p5-SMS-Send \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SMS::Send::TW::HiAir.3

.include <bsd.port.mk>
