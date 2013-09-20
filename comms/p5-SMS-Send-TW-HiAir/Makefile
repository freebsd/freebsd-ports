# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	SMS-Send-TW-HiAir
PORTVERSION=	0.02
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	SMS::Send driver for http://hiair.hinet.net/

BUILD_DEPENDS=	p5-SMS-Send>=0:${PORTSDIR}/comms/p5-SMS-Send \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-Crypt-SSLeay>=0.51:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		SMS::Send::TW::HiAir.3

NO_STAGE=	yes
.include <bsd.port.mk>
