# New ports collection makefile for:    p5-DBD-ODBC
# Date created:				Nov 30 2001
# Whom:	      				Clive Lin <clive@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-ODBC
PORTVERSION=	0.28
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	DBD module interfacing the ODBC databases

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
LIB_DEPENDS=	iodbc.3:${PORTSDIR}/databases/libiodbc

INSTALLS_SHLIB=	yes
PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	-o ${LOCALBASE}
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		DBD::ODBC.3

.include <bsd.port.mk>
