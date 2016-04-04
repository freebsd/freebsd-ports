# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	Date-Japanese-Era
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Conversion between Japanese Era / Gregorian calendar

BUILD_DEPENDS=	p5-Date-Calc>=0:devel/p5-Date-Calc \
		p5-Lingua-JA-Numbers>=0:japanese/p5-Lingua-JA-Numbers
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
