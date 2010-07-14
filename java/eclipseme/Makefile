# New ports collection makefile for:	eclipseme
# Date created:				July 22, 2004
# Whom:					past@ebs.gr
#
# $FreeBSD$
#

PORTNAME=	eclipseme
PORTVERSION=	0.4.6
PORTREVISION=	4
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eclipse J2ME Plugin

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/bin/ktoolbar:${PORTSDIR}/java/sun-wtk

NO_BUILD=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	pkg-message
SUB_LIST=	APP_HOME=${APP_HOME}
APP_HOME=	${PREFIX}/lib/eclipse/plugins/${PORTNAME}_${PORTVERSION}

.if defined(WITH_PROGUARD)
RUN_DEPENDS+=	${LOCALBASE}/share/proguard/lib/proguard.jar:${PORTSDIR}/java/proguard
.endif

do-install:
	@${MKDIR} ${PREFIX}/lib/eclipse/plugins
	@${CP} -R ${WRKSRC}/${PORTNAME}_${PORTVERSION} ${PREFIX}/lib/eclipse/plugins/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
