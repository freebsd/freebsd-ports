# Created by: Jui-Nan Lin <jnlin@freebsd.cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	SMS-Send-TW-HiAir
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	SMS::Send driver for http://hiair.hinet.net/

BUILD_DEPENDS=	p5-SMS-Send>=0:comms/p5-SMS-Send \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-Crypt-SSLeay>=0.51:security/p5-Crypt-SSLeay \
		p5-Text-Iconv>=0:converters/p5-Text-Iconv
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
