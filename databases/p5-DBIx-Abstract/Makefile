# New ports collection makefile for:	p5-DBIx-Abstract
# Date created:				6 Jan 2006
# Whom:					Jon Nistor <nistor@snickers.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Abstract
PORTVERSION=	1.006
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nistor@snickers.org
COMMENT=	DBIx::Abstract - DBI SQL abstraction

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DBIx::Abstract.3

.include <bsd.port.mk>
