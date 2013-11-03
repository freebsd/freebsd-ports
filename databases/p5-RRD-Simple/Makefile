# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	RRD-Simple
PORTVERSION=	1.44
PORTREVISION=	5
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Proc/NICOLAW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple interface to create and store data in RRD files

BUILD_DEPENDS=	rrdtool>=0:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
