# New ports collection makefile for:    DBD::mysql
# Date created:				27 Nov 2001
# Whom:	      				Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-mysql
PORTVERSION=	2.1018
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Bundle::DBD::mysql.3 DBD::mysql.3 DBD::mysql::INSTALL.3 \
		Mysql.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
