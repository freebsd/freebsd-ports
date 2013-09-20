# Created by: Timur I. Bakeyev <bat@cpan.org>
# $FreeBSD$

PORTNAME=	Relations-Query
PORTVERSION=	0.93
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Object for building queries with DBI/DBD::mysql

BUILD_DEPENDS=	p5-Relations>=0:${PORTSDIR}/databases/p5-Relations
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Relations::Query.3

NO_STAGE=	yes
.include <bsd.port.mk>
