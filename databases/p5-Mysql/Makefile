# New ports collection makefile for:    p5-MySQL
# Version required:			1.17
# Date created:				June 17th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1997/06/18 19:39:25 jfitz Exp $
#

DISTNAME=	Mysqlperl-1.17
PKGNAME=	p5-Mysql-1.17
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.tcx.se/Contrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql

USE_PERL5=	YES

MAN3=		Mysql.3
MANPREFIX=	${PREFIX}/lib/perl5

CONFIGURE_ENV+=	PREFIX=${PREFIX}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
