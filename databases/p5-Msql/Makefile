# New ports collection makefile for:    p5-Msql-modules
# Date created:				September 29th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-Msql-modules
PORTVERSION=	1.1811
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Msql
DISTNAME=	Msql-modules-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Perl5 modules for accessing MiniSQL (mSQL) databases

BUILD_DEPENDS=	${LOCALBASE}/lib/libmsql.a:${PORTSDIR}/databases/msql \
		${LOCALBASE}/lib/perl5/site_perl/Data/ShowTable.pm:${PORTSDIR}/devel/p5-Data-ShowTable \
		${LOCALBASE}/lib/perl5/site_perl/DBI.pm:${PORTSDIR}/databases/p5-DBI

BROKEN=		DEPENDS on databases/msql which is currently BROKEN, also perl5 upgrade

PERL_CONFIGURE=	YES
CONFIGURE_ENV+=	PREFIX=${PREFIX} MSQL_HOME=${PREFIX}

MAN1=		pmsql.1 dbimon.1
MAN3=		Msql.3 DBD::mSQL.3
MAN3PREFIX=	${PREFIX}/lib/perl5

.include <bsd.port.mk>
