# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SQL-Abstract-Limit
PORTVERSION=	0.141
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	SQL Portability layer for LIMIT emulation

RUN_DEPENDS=	p5-SQL-Abstract>=1.24:databases/p5-SQL-Abstract \
		p5-DBI>=0:databases/p5-DBI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
