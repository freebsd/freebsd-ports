# Created by: Ryan T. Dean <rtdean@cytherianage.net>
# $FreeBSD$

PORTNAME=	Unicode-MapUTF8
PORTVERSION=	1.11
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl class that implements conversion between arbitrary charsets

BUILD_DEPENDS=	p5-Unicode-Map>=0:${PORTSDIR}/converters/p5-Unicode-Map \
		p5-Unicode-String>=0:${PORTSDIR}/converters/p5-Unicode-String \
		p5-Unicode-Map8>=0:${PORTSDIR}/converters/p5-Unicode-Map8 \
		ja-p5-Jcode>=0:${PORTSDIR}/japanese/p5-Jcode
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
