# ex;ts=8
# Ports collection makefile for:	DBIx::TableHash
# Date created:			Sep 21, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	DBIx-TableHash
PORTVERSION=	1.05
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHTHORMAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tie a hash to a MySQL table + SQL utils

BUILD_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::TableHash.3

.include <bsd.port.mk>
