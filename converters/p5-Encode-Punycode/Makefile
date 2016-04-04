# Created by: Timur Bakeyev <timur@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Encode-Punycode
PORTVERSION=	1.001
PORTREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Encode plugin for Punycode

RUN_DEPENDS=	p5-Net-IDN-Encode>=0:textproc/p5-Net-IDN-Encode
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
