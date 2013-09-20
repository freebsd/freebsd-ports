# Created by: Erwin Lansing <erwin@lansing.dk>
# $FreeBSD$

PORTNAME=	Encode-compat
PORTVERSION=	0.07
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Compatibility interfaces for Encode.pm on Perl < 5.7.1

BUILD_DEPENDS=	p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Encode::compat.3 Encode::compat::Alias.3

NO_STAGE=	yes
.include <bsd.port.mk>
