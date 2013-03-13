# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Audio-Beep
PORTVERSION=	0.11
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to use your computer beeper in fancy ways

BUILD_DEPENDS=	beep:${PORTSDIR}/audio/beep
RUN_DEPENDS=	beep:${PORTSDIR}/audio/beep

PERL_CONFIGURE=	yes

MAN3=		Audio::Beep.3 Audio::Beep::BSD::beep.3

.include <bsd.port.mk>
