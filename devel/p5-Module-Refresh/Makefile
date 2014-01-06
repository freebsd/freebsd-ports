# Created by: aturetta@commit.it
# $FreeBSD$

PORTNAME=	Module-Refresh
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Refresh %INC files when updated on disk

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker>=6.42:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		p5-File-Temp>=0.19:${PORTSDIR}/devel/p5-File-Temp \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
