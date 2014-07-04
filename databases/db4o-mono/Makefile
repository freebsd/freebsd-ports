# Created by: pneumann@gmail.com
# $FreeBSD$

PORTNAME=	db4o
PORTVERSION=	${REALVERSION}.20
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.db4o.com/downloads/
PKGNAMESUFFIX=	-mono
DISTNAME=	${PORTNAME}-${REALVERSION}${PKGNAMESUFFIX}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	pneumann@gmail.com
COMMENT=	Database engine for storing object into files

USES=		mono

REALVERSION=	5.5

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${REALVERSION}

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
do-install:
	@(cd ${WRKSRC}/dll ; ${SETENV} MONO_SHARED_DIR=${WRKDIR} ${LOCALBASE}/bin/gacutil /root ${PREFIX}/lib /gacdir ${PREFIX}/lib /package 1.0 /i db4o.dll)

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc/; ${FIND} api \
		| ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${DOCSDIR}
	@cd ${WRKSRC}/doc/; ${FIND} tutorial \
		| ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${DOCSDIR}
	@${CHMOD} -R ugo-w,ugo+rX ${DOCSDIR}

.include <bsd.port.mk>
