# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Cache-BDB
PORTVERSION=	0.04
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	An object caching wrapper around BerkeleyDB

BUILD_DEPENDS=	p5-BerkeleyDB>=0:${PORTSDIR}/databases/p5-BerkeleyDB
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Cache::BDB.3

NO_STAGE=	yes
.include <bsd.port.mk>
