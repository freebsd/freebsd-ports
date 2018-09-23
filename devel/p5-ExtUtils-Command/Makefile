# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	ExtUtils-Command
PORTVERSION=	1.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Utilities to replace common UNIX commands

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	ExtUtils::Command has been re-incorporated to ExtUtils-MakeMaker since 7.06, use devel/ExtUtils-MakeMaker instead
EXPIRATION_DATE=2018-09-30

CONFLICTS=	p5-ExtUtils-MakeMaker-[7-9].[1-9]*

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
