# $FreeBSD$

PORTNAME=	automysqlbackup
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0_rc6
CATEGORIES=	databases
MASTER_SITES=	SF/automysqlbackup/AutoMySQLBackup/AutoMySQLBackup%20VER%203.0

MAINTAINER=	me@cschwarz.com
COMMENT=	Automatic MySQL Backup Tool

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

NO_BUILD=	yes

NO_WRKSUBDIR=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|' \
		${WRKSRC}/automysqlbackup

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/automysqlbackup	${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README		${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/automysqlbackup.conf	${STAGEDIR}${ETCDIR}/automysqlbackup.conf.sample

post-install:
	${MKDIR} ${STAGEDIR}/var/backups/automysqlbackup

.include <bsd.port.mk>
