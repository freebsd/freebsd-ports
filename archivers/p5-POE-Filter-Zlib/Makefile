# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	POE-Filter-Zlib
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE filter wrapped around Compress::Zlib

BUILD_DEPENDS=	p5-POE>=0.38:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		POE::Filter::Zlib.3 \
		POE::Filter::Zlib::Stream.3

.include <bsd.port.mk>

