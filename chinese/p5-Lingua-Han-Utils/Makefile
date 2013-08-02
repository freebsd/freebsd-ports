# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Lingua-Han-Utils
PORTVERSION=	0.12
CATEGORIES=	chinese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The utility tools of Chinese character(HanZi)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Encode-Detect-CJK>=0:${PORTSDIR}/converters/p5-Encode-Detect-CJK
RUN_DEPENDS=	p5-Encode-Detect-CJK>=0:${PORTSDIR}/converters/p5-Encode-Detect-CJK

USES=		perl5
USE_PERL5=	configure

MAN3=		Lingua::Han::Utils.3

.include <bsd.port.mk>
