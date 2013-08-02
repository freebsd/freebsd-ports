# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Lingua-Han-PinYin
PORTVERSION=	0.16
CATEGORIES=	chinese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve the Mandarin (PinYin) of Chinese character (HanZi)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Lingua-Han-Utils>=0.10:${PORTSDIR}/chinese/p5-Lingua-Han-Utils
RUN_DEPENDS=	p5-Lingua-Han-Utils>=0.10:${PORTSDIR}/chinese/p5-Lingua-Han-Utils

USES=		perl5
USE_PERL5=	configure

MAN3=		Lingua::Han::PinYin.3

.include <bsd.port.mk>
