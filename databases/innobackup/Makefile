# New ports collection makefile for:	innobackup
# Date created:		2008-09-18
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	innobackup
PORTVERSION=	1.5.2
CATEGORIES=	databases
MASTER_SITES=	http://www.innodb.com/download/ \
		http://files.gslin.org/Software/
DISTFILES=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	Making backups of InnoDB and MyISAM tables, indexes and .frm files

NO_BUILD=	yes
PLIST_FILES=	sbin/innobackup-${PORTVERSION}
USE_MYSQL=	yes
USE_PERL5=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-${PORTVERSION} ${PREFIX}/sbin

.include <bsd.port.mk>
