# ex:ts=8
# Ports collection makefile for:	impact
# Date created:			Mar 4, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	impact
PORTVERSION=	0.5.3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Impact-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic Finite Element Program Suite

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/Impact
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

SUB_FILES=	impact impactgui
SUB_LIST=	DIR=${PREFIX}/impact

PLIST_FILES=	bin/impact bin/impactgui

do-install:
	@${MKDIR} ${PREFIX}/impact
	${CP} -R ${WRKSRC}/ ${PREFIX}/impact
	${INSTALL_SCRIPT} ${WRKDIR}/impact ${WRKDIR}/impactgui ${PREFIX}/bin

post-install:
	@${FIND} ${PREFIX}/impact ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/impact -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
