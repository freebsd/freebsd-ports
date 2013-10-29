# Created by: Anes Muhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	Declare-Constraints-Simple
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PHAYLON
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Declarative Validation of Perl Data Structures

BUILD_DEPENDS=	p5-Class-Inspector>=1.24:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased \
		p5-Carp-Clan>=5.3:${PORTSDIR}/devel/p5-Carp-Clan
RUN_DEPENDS=	p5-Class-Inspector>=1.24:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased \
		p5-Carp-Clan>=5.3:${PORTSDIR}/devel/p5-Carp-Clan

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
