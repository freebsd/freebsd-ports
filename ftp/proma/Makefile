# New ports collection makefile for:    proma
# Date created:         25.08.2003
# Whom:                 HSIN-HSIUNG CHANG <sexbear@tmu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	proma
PORTVERSION=	0.8.1
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sexbear@tmu.edu.tw
COMMENT=	Administrating a ProFTPd server storing users in a MySQL database

NO_BUILD=	yes

MYADMDIR?=	www/data/proma

PLIST_SUB+=	MYADMDIR=${MYADMDIR}

do-install:
	${MKDIR} ${PREFIX}/${MYADMDIR}
	@${FIND} ${WRKSRC} ! -path '*/CVS*' | \
		${XARGS} -n1 ${SH} -c 'if ${TEST} -d $$0; \
			then ${MKDIR} ${PREFIX}/${MYADMDIR}$${0#${WRKSRC}}; \
			else ${INSTALL_DATA} $$0 ${PREFIX}/${MYADMDIR}$${0#${WRKSRC}}; fi'
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.mk>
