# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	Test-Prereq
PORTVERSION=	1.039
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Check if Makefile.PL has the right pre-requisites

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Info>=0:devel/p5-Module-Info
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
