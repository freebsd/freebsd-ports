# New ports collection makefile for:	p5-DBI
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBI
PORTVERSION=	1.14
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBI
PKGNAMEPREFIX=	p5-

MAINTAINER=	vanilla@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/RPC/PlServer.pm:${PORTSDIR}/net/p5-PlRPC

USE_PERL5=	yes

MAN1=		dbiproxy.1 \
		dbish.1
MAN3=		Bundle::DBI.3 \
		DBD::ADO.3 \
		DBD::Multiplex.3 \
		DBD::Proxy.3 \
		DBI.3 \
		DBI::DBD.3 \
		DBI::FAQ.3 \
		DBI::Format.3 \
		DBI::ProxyServer.3 \
		DBI::Shell.3 \
		DBI::W32ODBC.3 \
		Win32::DBIODBC.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
			PREFIX="${PREFIX}" CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
