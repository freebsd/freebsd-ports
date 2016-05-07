# Created by: clsung
# $FreeBSD$

PORTNAME=	Module-Starter
PORTVERSION=	1.71
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple starter kit for any Perl module

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Path-Class>=0:devel/p5-Path-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:1.470

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
