# ex:ts=8
# Ports collection makefile for:	impact
# Date created:			Mar 4, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	impact
PORTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	cad java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION}
DISTNAME=	Impact-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Dynamic Finite Element Program Suite

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/Impact
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	impact impactgui

PLIST_FILES=	bin/impact bin/impactgui

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/impact ${WRKDIR}/impactgui ${PREFIX}/bin

post-install:
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
