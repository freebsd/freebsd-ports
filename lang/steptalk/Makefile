# New ports collection makefile for:	steptalk
# Date created:         29 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	steptalk
PORTVERSION=	0.10.0
PORTREVISION=	4
CATEGORIES=	lang gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs
DISTNAME=	StepTalk-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	The official GNUstep scripting framework

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_GUI=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/StepTalk
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}
GDL2_PORT?=	databases/gdl2

.if !defined(STEPTALK_WITHOUT_GDL2)
USE_GNUSTEP_LOCAL_LIBS+=	EOInterface:${GDL2_PORT}
PLIST_SUB+=	WITH_GDL2=""

post-configure:
	${REINPLACE_CMD} -e 's|-lgnustep-db2|-lEOAccess|' \
		 -e 's|-lgnustep-db2control|-lEOControl|' \
		 -e 's|-lgnustep-db2modeler|-lEOModeler|' \
		${WRKSRC}/Modules/GDL2/GNUmakefile
.else
PLIST_SUB+=	WITH_GDL2="@comment "

post-configure:
	${REINPLACE_CMD} -e 's|bundle.make|rules.make|' \
		${WRKSRC}/Modules/GDL2/GNUmakefile
.endif

.include <bsd.port.mk>
