# New ports collection makefile for:    mysql-editor
# Date created:				Mar 14, 2000
# Whom:	      				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mysql-editor
PORTVERSION=	0.2
CATEGORIES=	databases www
MASTER_SITES=	http://sorry.vse.cz/~xzemt02/mysql/ \
		http://www.mysql.com/Contrib/
DISTNAME=	${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${CGI_BIN}:${PORTSDIR}/www/apache13

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

.include <bsd.port.mk>
