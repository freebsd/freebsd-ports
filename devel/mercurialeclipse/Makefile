# New ports collection makefile for:	mercurialeclipse
# Date created:		2009-06-27
# Whom:			Edmondas Girkantas <eg@fbsd.lt>
#
# $FreeBSD$
#

PORTNAME=	mercurialeclipse
PORTVERSION=	1.4.1286
CATEGORIES=	devel java
MASTER_SITES=	http://www.vectrace.com/eclipse-update/plugins/
DISTNAME=	com.vectrace.MercurialEclipse_${PORTVERSION}
EXTRACT_SUFX=	.jar
DIST_SUBDIR=	eclipse
EXTRACT_ONLY=

MAINTAINER=	eg@fbsd.lt
COMMENT=	A mercurial plugin for the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

PLIST_SUB=	VER=${PORTVERSION}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ECLIPSE=	${PREFIX}/eclipse
PLUGINS=	plugins

do-install:
	@${MKDIR} ${ECLIPSE}/${PLUGINS}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${ECLIPSE}/${PLUGINS}/

.include <bsd.port.mk>
