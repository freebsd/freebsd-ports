# New ports collection makefile for:    p5-Msql
# Version required:			1.1702
# Date created:				September 29th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.11 1997/06/15 03:14:05 jfitz Exp $
#

DISTNAME=	MsqlPerl-1.1702
PKGNAME=	p5-Msql-1.1702
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Msql

MAINTAINER=	jfitz@FreeBSD.ORG

# Uncomment this if you want to build against the msql-beta (v2) port instead
# of the original v1.16 port
#USE_MSQLBETA=	YES

.if defined(USE_MSQLBETA)
BUILD_DEPENDS=	${PREFIX}/lib/libmsql.a:${PORTSDIR}/databases/msql-beta/
CONFIGURE_ENV+=	USE_MSQLBETA=${USE_MSQLBETA}
.else
BUILD_DEPENDS=	${PREFIX}/Minerva/lib/libmsql.a:${PORTSDIR}/databases/msql/
.endif

CONFIGURE_ENV+=	PREFIX=${PREFIX}

USE_PERL5=	YES

MAN1=		pmsql.1
MAN3=		Msql.3
MAN3PREFIX=	${PREFIX}/lib/perl5

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
