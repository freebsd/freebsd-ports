# New ports collection makefile for:	p5-DBI
# Version required:			1.06
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.19 1999/01/21 17:50:56 vanilla Exp $
#

DISTNAME=	DBI-1.06
PKGNAME=	p5-DBI-1.06
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBI

MAINTAINER=	vanilla@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/RPC/pServer.pm:${PORTSDIR}/net/p5-pRPC

USE_PERL5=	YES
CONFIGURE_ARGS=	PREFIX=${PREFIX}

MAN1=		dbiproxy.1 \
		dbish.1
MAN3=		DBD::Proxy.3 \
		DBI.3 \
		DBI::DBD.3 \
		DBI::FAQ.3 \
		DBI::Format.3 \
		DBI::ProxyServer.3 \
		DBI::Shell.3 \
		DBI::W32ODBC.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL ${CONFIGURE_ARGS}

.include <bsd.port.mk>
