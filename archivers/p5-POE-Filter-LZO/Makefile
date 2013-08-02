# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	POE-Filter-LZO
PORTVERSION=	1.7.0
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE filter wrapped around Compress::LZO

BUILD_DEPENDS=	p5-Compress-LZO>=1.08:${PORTSDIR}/archivers/p5-Compress-LZO \
		p5-POE>=0.38:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		POE::Filter::LZO.3

.include <bsd.port.mk>
