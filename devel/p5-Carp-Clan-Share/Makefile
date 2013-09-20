# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Carp-Clan-Share
PORTVERSION=	0.013
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Carp
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Share your Carp::Clan settings with your whole Clan

BUILD_DEPENDS=	p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Carp::Clan::Share.3

NO_STAGE=	yes
.include <bsd.port.mk>
