# $FreeBSD$

PORTNAME=	Lingua-JA-Moji
PORTVERSION=	0.36
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to handle many kinds of Japanese characters

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Convert-Moji>=0.05:converters/p5-Convert-Moji
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.pre.mk>
PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-
.include <bsd.port.post.mk>
