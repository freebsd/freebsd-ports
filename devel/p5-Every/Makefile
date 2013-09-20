# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Every
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEODOR
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Return true every N cycles or S seconds

BUILD_DEPENDS=	p5-Devel-Callsite>=0.04:${PORTSDIR}/devel/p5-Devel-Callsite
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Every.3

NO_STAGE=	yes
.include <bsd.port.mk>
