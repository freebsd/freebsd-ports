# $FreeBSD$

PORTNAME=	Time-Crontab
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to parse crontab date and time field

RUN_DEPENDS=	\
	p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
	p5-Set-Crontab>=1.03:devel/p5-Set-Crontab
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
