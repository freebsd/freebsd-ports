# New ports collection makefile for:		Castle.ActiveRecord
# Date created:                         	17 Dec 2005
# Whom:                                 	pneumann@gmail.com
#
# $FreeBSD$
#   $Id: Makefile,v 1.1 2005/12/18 20:45:20 tmclau02 Exp $
#

PORTNAME=	db4o
PORTVERSION=	5.0.18
CATEGORIES=	databases
MASTER_SITES=	http://www.db4o.com/downloads/
PKGNAMESUFFIX=	-mono
DISTNAME=	${PORTNAME}-5.0${PKGNAMESUFFIX}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	pneumann@gmail.com
COMMENT=	A database engine for storing object into files

RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

NO_BUILD=	yes

do-install:
	@(cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/dll ; ${SETENV} MONO_SHARED_DIR=${WRKDIR} ${LOCALBASE}/bin/gacutil /root ${PREFIX}/lib /gacdir ${PREFIX}/lib /package 1.0 /i db4o.dll)

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc/; ${FIND} api \
	| ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${DOCSDIR}
	@cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc/; ${FIND} tutorial \
	| ${CPIO} -pdmv -R ${DOCOWN}:${DOCGRP} ${DOCSDIR}
	@${CHMOD} -R ugo-w,ugo+rX ${DOCSDIR}
.endif

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
