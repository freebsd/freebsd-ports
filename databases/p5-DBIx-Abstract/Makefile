# Created by: Jon Nistor <nistor@snickers.org>
# $FreeBSD$

PORTNAME=	DBIx-Abstract
PORTVERSION=	1.010
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	nistor@snickers.org
COMMENT=	DBIx::Abstract - DBI SQL abstraction

BUILD_DEPENDS=	p5-Check-ISA>=0:devel/p5-Check-ISA \
		p5-DBI>=0:databases/p5-DBI
RUN_DEPENDS=	p5-Check-ISA>=0:devel/p5-Check-ISA \
		p5-DBI>=0:databases/p5-DBI
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
