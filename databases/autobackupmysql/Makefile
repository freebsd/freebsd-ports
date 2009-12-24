# New ports collection makefile for:	autobackupmysql
# Date created:		2009-12-21
# Whom:			Frank Wall <fw@moov.de>
#
# $FreeBSD$
#

PORTNAME=	autobackupmysql
PORTVERSION=	1.1
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.sh

MAINTAINER=	fw@moov.de
COMMENT=	Make daily, weekly and monthly backups of your MySQL databases

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

.if defined(WITH_OLDBASH)
RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash3
.endif

NO_BUILD=	yes
PLIST_FILES=	sbin/autobackupmysql.sh

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh ${PREFIX}/sbin

.include <bsd.port.mk>
