# Created by: mat
# $FreeBSD$

PORTNAME=	DBIx-Ease
PORTVERSION=	0.07
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_LOCAL:S/$/:local/} ${MASTER_SITE_PERL_CPAN:S/$/:cpan/}
MASTER_SITE_SUBDIR=	mat/:local DBIx/:cpan
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:local,cpan

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Less-code DBI interactions for all drivers

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
