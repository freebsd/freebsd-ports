# New ports collection makefile for:    DBD::mysql
# Date created:				27 Nov 2001
# Whom:	      				Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-mysql
PORTVERSION=	3.0004
PORTREVISION=	0
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT?=	MySQL driver for the Perl5 Database Interface (DBI)

CONFLICTS?=	p5-Mysql-modules-[0-9]* p5-DBD-mysql4[0-9]-[0-9]* p5-DBD-mysql5[0-9]-[0-9]*

USE_MYSQL=	yes

PERL_CONFIGURE=	yes

MAN3=	Bundle::DBD::mysql.3 DBD::mysql.3 DBD::mysql::INSTALL.3 Mysql.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

post-patch:
.if ${PERL_LEVEL} < 500600
	@${PERL} -pi -e 's/(?:use|no) warnings;?//; s/our (%\w+)/use vars qw(\1);\n\1/' \
		${WRKSRC}/lib/DBD/mysql/GetInfo.pm
.endif
	@${PERL} -pi -e 's/$$/ || MYSQL_VERSION_ID == 50000/ if $$. == 107' \
		${WRKSRC}/mysql.xs

.include <bsd.port.post.mk>
