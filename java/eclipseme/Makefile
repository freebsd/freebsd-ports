# New ports collection makefile for:	eclipseme
# Date created:				July 22, 2004
# Whom:					past@ebs.gr
#
# $FreeBSD$
#

PORTNAME=	eclipseme
PORTVERSION=	0.4.5
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	past@ebs.gr
COMMENT=	Eclipse J2ME Plugin

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/bin/ktoolbar:${PORTSDIR}/java/sun-wtk

NO_BUILD=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
APP_HOME=	${PREFIX}/eclipse/plugins/${PORTNAME}_${PORTVERSION}

.if defined(WITH_PROGUARD)
RUN_DEPENDS+=	${LOCALBASE}/share/proguard/lib/proguard.jar:${PORTSDIR}/java/proguard
.endif

do-install:
		@${CP} -r ${WRKSRC}/${PORTNAME}_${PORTVERSION} ${PREFIX}/eclipse/plugins/

post-install:
	@${SED} -e 's,%%PREFIX%%,${APP_HOME},' \
		< ${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
