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
MASTER_SITE_SUBDIR=Contrib/Old-Versions
DISTNAME=	${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	CGI scripts in Perl to edit your MySQL tables

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_APACHE=	1.3
NO_BUILD=	yes
USE_PERL5=	yes

CGI_BIN=	${LOCALBASE}/www/cgi-bin

do-install:
	${MKDIR} ${CGI_BIN}/mysql-editor
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${CGI_BIN}/mysql-editor/
	${INSTALL_DATA} ${WRKSRC}/index.html ${CGI_BIN}/mysql-editor/
	${INSTALL_DATA} ${WRKSRC}/dat.conf ${CGI_BIN}/mysql-editor/dat.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mysql-editor
	${INSTALL_DATA} ${WRKSRC}/readme.html ${DOCSDIR}/
.endif

.include <bsd.port.mk>
