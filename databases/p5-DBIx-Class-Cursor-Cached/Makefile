# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-Cursor-Cached
PORTVERSION=	1.001.002
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cursor class with built-in caching support

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Carp-Clan>=6.0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-DBIx-Class>=0.08124:${PORTSDIR}/databases/p5-DBIx-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Cache-Cache>=0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
