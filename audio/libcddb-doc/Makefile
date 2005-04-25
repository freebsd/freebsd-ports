# New ports collection makefile for:	libcddb-doc
# Date created:		2005-04-24
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcddb-doc
PORTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libcddb

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libcddb documentation

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/output

do-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}

.include <bsd.port.mk>
