# Created by: Maxim Maximov (mcsi@agava.com)
# $FreeBSD$

PORTNAME=	Unicode-Lite
PORTVERSION=	0.12
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for easy conversion between encodings

BUILD_DEPENDS=	p5-Unicode-String>=0:${PORTSDIR}/converters/p5-Unicode-String \
		p5-Unicode-Map>=0:${PORTSDIR}/converters/p5-Unicode-Map \
		p5-enum>=0:${PORTSDIR}/devel/p5-enum
RUN_DEPENDS:=	${BUILD_DEPENDS}

BROKEN=		Overwrites bin/map from converters/p5-Unicode-Map

USES=		perl5
USE_PERL5=	configure

MAN3=		Unicode::Lite.3

.include <bsd.port.mk>
