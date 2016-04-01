# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	GD-Graph3d
PORTVERSION=	0.63
PORTREVISION=	6
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Creates 3D charts with GD::Graph and GD

BUILD_DEPENDS=	p5-GD-Graph>=0:graphics/p5-GD-Graph
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 dos2unix
USE_PERL5=	configure
DOS2UNIX_FILES=	lib/GD/Graph3d.pm # pod2man doesn't work without this

.include <bsd.port.mk>
