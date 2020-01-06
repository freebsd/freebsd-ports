# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Term-Menus
PORTVERSION=	3.024
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:REEDFISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Create Powerful Terminal, Console, and CMD Environment Menus

LICENSE=	AGPLv3

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>0:devel/p5-Capture-Tiny \
		p5-Data-Dump-Streamer>0:devel/p5-Data-Dump-Streamer \
		p5-Devel-Symdump>0:devel/p5-Devel-Symdump \
		p5-PadWalker>0:devel/p5-PadWalker \
		p5-Term-RawInput>=1.20:devel/p5-Term-RawInput \
		p5-Term-ReadKey>0:devel/p5-Term-ReadKey

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
