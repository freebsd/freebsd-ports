# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	Time-Piece-Range
PORTVERSION=	1.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Time::Piece::Range - deal with a range of Time::Piece objects

BUILD_DEPENDS=	p5-Time-Piece>=0:${PORTSDIR}/devel/p5-Time-Piece \
		p5-Date-Range>=0:${PORTSDIR}/devel/p5-Date-Range
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
