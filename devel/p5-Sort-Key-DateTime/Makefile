# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sort-Key-DateTime
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for sorting objects by some DateTime key

RUN_DEPENDS=	p5-DateTime>=0.28:${PORTSDIR}/devel/p5-DateTime \
		p5-Sort-Key>=1.28:${PORTSDIR}/devel/p5-Sort-Key
BUILD_DEPENDS=  ${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
