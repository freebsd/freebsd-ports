# New ports collection makefile for:    mysql-editor
# Date created:				Mar 14, 2000
# Whom:	      				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mysql-editor
PORTVERSION=	0.2
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=Contrib
DISTNAME=	${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	CGI scripts in Perl to edit your MySQL tables

RUN_DEPENDS=	${CGI_BIN}:${PORTSDIR}/${APACHE_PORT}

NO_BUILD=	True

CGI_BIN=	${LOCALBASE}/www/cgi-bin

do-install:
	${MKDIR} ${CGI_BIN}/mysql-editor
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${CGI_BIN}/mysql-editor/
	${INSTALL_DATA} ${WRKSRC}/index.html ${CGI_BIN}/mysql-editor/
	${INSTALL_DATA} ${WRKSRC}/dat.conf ${CGI_BIN}/mysql-editor/dat.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mysql-editor
	${INSTALL_DATA} ${WRKSRC}/readme.html ${PREFIX}/share/doc/mysql-editor
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
