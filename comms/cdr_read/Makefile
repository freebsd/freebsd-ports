# New ports collection makefile for: cdr_read
# Date created:    15 June 2004
# Whom:     Konstantin Reznichenko <kot@premierbank.dp.ua>
#
# $FreeBSD$
#

PORTNAME=	cdr_read
PORTVERSION=	1.09
CATEGORIES=	comms
MASTER_SITES=	http://www.gamma.ru/~avk/
DISTNAME=	cdrr109

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for reading of the call detail records from PBX

NO_WRKSUBDIR=	yes

PORTDOCS=	readme.txt
PLIST_FILES=	sbin/cdr_read

post-patch:
	@${TR} -d "\015" < ${WRKDIR}/readme_eng.txt > ${WRKDIR}/readme.txt

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${PREFIX}/sbin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
