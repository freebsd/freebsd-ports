# Created by: Philip Paeps <philip@paeps.cx>
# $FreeBSD$

PORTNAME=	Date-Roman
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Perl module to play with Roman dates

BUILD_DEPENDS=	p5-Roman>=0:${PORTSDIR}/math/p5-Roman
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Date::Roman.3

NO_STAGE=	yes
.include <bsd.port.mk>
