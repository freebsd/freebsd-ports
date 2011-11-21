# New ports collection makefile for:	cdr_read
# Date created:				15 June 2004
# Whom:				Konstantin Reznichenko <kot@premierbank.dp.ua>
#
# $FreeBSD$
#

PORTNAME=	cdr_read
PORTVERSION=	1.09
CATEGORIES=	comms
MASTER_SITES=	http://www.gamma.ru/~avk/
DISTNAME=	cdrr${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for reading of the call detail records from PBX

USE_DOS2UNIX=	readme_eng.txt
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
NO_WRKSUBDIR=	yes

PLIST_FILES=	sbin/cdr_read
PORTDOCS=	*

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/readme_eng.txt ${DOCSDIR}/readme.txt
.endif

.include <bsd.port.mk>
