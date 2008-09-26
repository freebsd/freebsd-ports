# New ports collection makefile for:	innobackup
# Date created:		2008-09-18
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	innobackup
PORTVERSION=	1.4.0
CATEGORIES=	databases
MASTER_SITES=	http://www.innodb.com/download/
DISTFILES=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	Making backups of InnoDB and MyISAM tables, indexes and .frm files

NO_BUILD=	yes
PLIST_FILES=	sbin/innobackup-${PORTVERSION}
USE_MYSQL=	yes
USE_PERL5=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${PORTNAME}-${PORTVERSION} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-${PORTVERSION} ${PREFIX}/sbin

.include <bsd.port.mk>
