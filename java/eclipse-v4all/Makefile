# New ports collection makefile for:	eclipse-v4all
# Date created:				Mon Mar 14 05:39:49 GMT 2005
# Whom:					wes@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	v4all
PORTVERSION=	2.1.1.9
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_2_1_1_9
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	wes@freebsd.org
COMMENT=	An Eclipse Plugin for Designing Java Swing & SWT GUIs

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}

ECLIPSE=	${PREFIX}/eclipse

do-install:
	@${CP} -r ${WRKSRC}/features/* ${ECLIPSE}/features
	@${CP} -r ${WRKSRC}/plugins/* ${ECLIPSE}/plugins

.include <bsd.port.mk>
