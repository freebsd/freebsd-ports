# New ports collection makefile for:	xalan-j
# Date created:		21 February 2001
# Whom:			znerd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xalan-j
PORTVERSION=	2.1.0
CATEGORIES=	java textproc
MASTER_SITES=	http://xml.apache.org/dist/${PORTNAME}/ \
		http://www.metaverse.nl/~ernst/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	znerd@FreeBSD.org

RUN_DEPENDS=    ${JAVAVM}:${PORTSDIR}/java/javavmwrapper

JAVAVM?=        ${LOCALBASE}/bin/javavm

NO_BUILD=	YES
PORTDESTDIR=	${PREFIX}/${PORTNAME}${PORTVERSION}

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

do-install:
	@${MKDIR} ${PORTDESTDIR}
	@${CP} -r ${WRKSRC}/* ${PORTDESTDIR}

.include <bsd.port.mk>
