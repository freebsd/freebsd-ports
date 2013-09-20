# Created by: Jon Nistor <nistor@snickers.org>
# $FreeBSD$

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

USES=		perl5
USE_PERL5=	configure

MAN3=		DBIx::Abstract.3

NO_STAGE=	yes
.include <bsd.port.mk>
