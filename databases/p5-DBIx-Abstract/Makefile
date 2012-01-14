# New ports collection makefile for:	p5-DBIx-Abstract
# Date created:				6 Jan 2006
# Whom:					Jon Nistor <nistor@snickers.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Abstract
PORTVERSION=	1.010
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	nistor@snickers.org
COMMENT=	DBIx::Abstract - DBI SQL abstraction

BUILD_DEPENDS=	p5-Check-ISA>=0:${PORTSDIR}/devel/p5-Check-ISA \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	p5-Check-ISA>=0:${PORTSDIR}/devel/p5-Check-ISA \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
TEST_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

PERL_CONFIGURE=	yes

MAN3=		DBIx::Abstract.3

.include <bsd.port.mk>
