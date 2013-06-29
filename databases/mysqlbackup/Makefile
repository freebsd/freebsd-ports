# Created by: Alexey Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	mysqlbackup
PORTVERSION=	2.7
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Creates MySQL backups on a periodic basis

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_MYSQL=	yes
NO_BUILD=	yes

PERIODICS=	200.mysqlbackup.daily \
		200.mysqlbackup.weekly \
		200.mysqlbackup.monthly

MAN1=		mysqlbackup.1
PLIST_FILES=	bin/mysqlbackup \
		${PERIODICS:C,^(.*)\.(.*)$,\2/\1,:S,^,etc/periodic/,}
PLIST_DIRS=	${PERIODICS:C,^(.*)\.(.*)$,etc/periodic/\2,:u} \
		etc/periodic

pre-install:
	${REINPLACE_CMD} ${SUB_LIST:S,$,!g,:S,^, -e s!%%,:S,=,%%!,} \
		${PERIODICS:S,^,${WRKSRC}/,}

do-install:
.for periodic in ${PERIODICS}
	${MKDIR} ${PREFIX}/etc/periodic/${periodic:E}
	${INSTALL_SCRIPT} ${WRKSRC}/${periodic} \
		${PREFIX}/etc/periodic/${periodic:E}/${periodic:R}
.endfor
	${INSTALL_MAN} ${WRKSRC}/mysqlbackup.1 \
		${MAN1PREFIX}/man/man1/mysqlbackup.1
	${INSTALL_SCRIPT} ${WRKSRC}/mysqlbackup ${PREFIX}/bin/mysqlbackup

.include <bsd.port.mk>
