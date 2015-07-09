# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBD-Pg
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	32

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Provides access to PostgreSQL databases through the DBI

DEPRECATED=	Use databases/p5-DBD-Pg instead, compatability probles are fixed
EXPIRATION_DATE=	2015-07-22

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=1.614:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS_INSTALL=	p5-DBD-Pg-[0123].*

USES=		pgsql perl5
USE_PERL5=	configure

.include <bsd.port.mk>
