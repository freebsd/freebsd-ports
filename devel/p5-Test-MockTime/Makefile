# Created by: Timur I. Bakeyev <bat@cpan.org>
# $FreeBSD$

PORTNAME=	Test-MockTime
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Replaces actual time with simulated time

BUILD_DEPENDS=	p5-Time-Piece>=0:${PORTSDIR}/devel/p5-Time-Piece
RUN_DEPENDS=	p5-Time-Piece>=0:${PORTSDIR}/devel/p5-Time-Piece

USES=		perl5
USE_PERL5=	configure

MAN3=		Test::MockTime.3

NO_STAGE=	yes
.include <bsd.port.mk>
