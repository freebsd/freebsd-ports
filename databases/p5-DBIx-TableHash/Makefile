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
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx \
			../../authors/id/C/CH/CHTHORMAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tie a hash to a mysql table + SQL utils

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::TableHash.3

.include <bsd.port.mk>
