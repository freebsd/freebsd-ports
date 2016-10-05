# Created by: Alexey Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	mysqlbackup
PORTVERSION=	2.8
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Creates MySQL backups on a periodic basis

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		mysql
NO_BUILD=	yes

PERIODICS=	200.mysqlbackup.daily \
		200.mysqlbackup.weekly \
		200.mysqlbackup.monthly

PLIST_FILES=	bin/mysqlbackup \
		${PERIODICS:C,^(.*)\.(.*)$,\2/\1,:S,^,etc/periodic/,} \
		man/man1/mysqlbackup.1.gz

pre-install:
	${REINPLACE_CMD} ${SUB_LIST:S,$,!g,:S,^, -e s!%%,:S,=,%%!,} \
		${PERIODICS:S,^,${WRKSRC}/,}

do-install:
.for periodic in ${PERIODICS}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/${periodic:E}
	${INSTALL_SCRIPT} ${WRKSRC}/${periodic} \
		${STAGEDIR}${PREFIX}/etc/periodic/${periodic:E}/${periodic:R}
.endfor
	${INSTALL_MAN} ${WRKSRC}/mysqlbackup.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/mysqlbackup.1
	${INSTALL_SCRIPT} ${WRKSRC}/mysqlbackup \
		${STAGEDIR}${PREFIX}/bin/mysqlbackup

.include <bsd.port.mk>
