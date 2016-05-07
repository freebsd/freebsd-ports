# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	RRD-Simple
PORTVERSION=	1.44
PORTREVISION=	7
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN/Proc/NICOLAW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple interface to create and store data in RRD files

BUILD_DEPENDS=	rrdtool:databases/rrdtool
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
