# New ports collection Makefile for:		soapui
# Date created:					2007-07-25
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	soapui
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop application for dealing with web services over HTTP

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_JAVA=	1.5+
USE_ZIP=	yes
PLIST_SUB+=	VER=${PORTVERSION}

do-build:
	${REINPLACE_CMD} 's,export SOAPUI_HOME,export SOAPUI_HOME=${DATADIR},' ${WRKSRC}/bin/soapui.sh

do-install:
	${MKDIR} ${DATADIR}/bin
	${MKDIR} ${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/bin/soapui-${PORTVERSION}.jar ${DATADIR}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DATADIR}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/soapui.sh ${PREFIX}/bin

.include <bsd.port.mk>
