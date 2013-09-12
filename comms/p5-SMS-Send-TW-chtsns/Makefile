# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	SMS-Send-TW-chtsns
PORTVERSION=	0.03
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	SMS::Send driver for SNS service of CHT

RUN_DEPENDS=	p5-SMS-Send>=0:${PORTSDIR}/comms/p5-SMS-Send \
  		p5-Switch>=0:${PORTSDIR}/lang/p5-Switch \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		SMS::Send::TW::chtsns.3

.include <bsd.port.mk>
