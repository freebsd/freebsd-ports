# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-SQLite-Simple
PORTVERSION=	0.34
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy access to SQLite databases using objects

BUILD_DEPENDS=	p5-Class-Gomor>=0:${PORTSDIR}/devel/p5-Class-Gomor \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
