# New ports collection makefile for:	p5-Pg
# Date created:				October 19th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pg
PORTVERSION=	1.9.0
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pg
PKGNAMEPREFIX=	p5-
DISTNAME=	pgsql_perl5-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	pq.2:${PORTSDIR}/databases/postgresql7

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	POSTGRES_INCLUDE=${LOCALBASE}/pgsql/include \
		POSTGRES_LIB=${LOCALBASE}/pgsql/lib

MAN3=		Pg.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
