# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Term-Menus
PORTVERSION=	2.96
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:REEDFISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Create Powerful Terminal, Console, and CMD Environment Menus

LICENSE=	AGPLv3

BUILD_DEPENDS=	p5-Data-Dump-Streamer>0:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
		p5-Devel-Symdump>0:${PORTSDIR}/devel/p5-Devel-Symdump \
		p5-PadWalker>0:${PORTSDIR}/devel/p5-PadWalker \
		p5-Term-RawInput>=1.20:${PORTSDIR}/devel/p5-Term-RawInput \
		p5-Term-ReadKey>0:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
