# New ports collection makefile for:    DBD::mysql
# Date created:				27 Nov 2001
# Whom:	      				Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-mysql
PORTVERSION=	2.9003
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	MySQL driver for the Perl5 Database Interface (DBI)

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.10)
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.else
.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.14)
LIB_DEPENDS=	mysqlclient.14:${PORTSDIR}/databases/mysql41-client
.else
LIB_DEPENDS=	mysqlclient.12:${PORTSDIR}/databases/mysql40-client
.endif
.endif

PERL_CONFIGURE=	yes

MAN3=	Bundle::DBD::mysql.3 DBD::mysql.3 DBD::mysql::INSTALL.3 Mysql.3

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
