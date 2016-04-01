# Created by: Jui-Nan Lin <jnlin@freebsd.cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	SMS-Send-TW-Socket2Air
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	SMS::Send driver for Socket2Air

RUN_DEPENDS=	p5-SMS-Send>=0:comms/p5-SMS-Send \
		p5-Switch>=0:lang/p5-Switch \
		p5-libwww>=0:www/p5-libwww \
		p5-Text-Iconv>=0:converters/p5-Text-Iconv
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
