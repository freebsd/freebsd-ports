# New ports collection makefile for:	jakarta-ant
# Date created:		21 February 2001
# Whom:			ernst@jollem.com
#
# $FreeBSD$
#

PORTNAME=	xalan-j
PORTVERSION=	2.0.0
CATEGORIES=	java textproc
MASTER_SITES=	http://xml.apache.org/dist/${PORTNAME}/
DISTNAME=	${PORTNAME}_2_0_0

MAINTAINER=	ernst@jollem.com

RUN_DEPENDS=	${LOCALBASE}/linux-jdk1.3.0/bin/java:${PORTSDIR}/java/linux-jdk13

NO_BUILD=	YES
PORTDESTDIR=	${PREFIX}/${PORTNAME}${PORTVERSION}

do-install:
	@${MKDIR} ${PORTDESTDIR}
	@${CP} -r ${WRKSRC}/* ${PORTDESTDIR}

.include <bsd.port.mk>
