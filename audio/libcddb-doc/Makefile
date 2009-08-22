# New ports collection makefile for:	libcddb-doc
# Date created:				2005-04-24
# Whom:					Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcddb-doc
PORTVERSION=	1.3.0
CATEGORIES=	audio
MASTER_SITES=	SF/libcddb/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libcddb documentation

USE_BZIP2=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/output

do-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}

.include <bsd.port.mk>
