# New ports collection makefile for:	databases/p5-Relations-Query
# Date created:				1 Aug 2006
# Whom:					Timur I. Bakeyev <bat@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Relations-Query
PORTVERSION=	0.93
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	timur@FreeBSD.org
COMMENT=	Object for building queries with DBI/DBD::mysql

BUILD_DEPENDS=	p5-Relations>=0:${PORTSDIR}/databases/p5-Relations
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Relations::Query.3

.include <bsd.port.mk>
