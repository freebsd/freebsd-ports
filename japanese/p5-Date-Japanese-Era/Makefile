# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	Date-Japanese-Era
PORTVERSION=	0.07
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Conversion between Japanese Era / Gregorian calendar

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Date-Calc>=0:devel/p5-Date-Calc \
		ja-p5-Lingua-JA-Numbers>=0:japanese/p5-Lingua-JA-Numbers

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	y

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
