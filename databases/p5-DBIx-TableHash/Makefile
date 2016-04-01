# Created by: ijliao
# $FreeBSD$

PORTNAME=	DBIx-TableHash
CATEGORIES=	databases perl5
PORTVERSION=	1.05
PORTREVISION=	1
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHTHORMAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tie a hash to a MySQL table + SQL utils

BUILD_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
