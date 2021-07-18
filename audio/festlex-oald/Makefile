# Created by: trevor

PORTNAME=	festlex-oald
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	audio accessibility
MASTER_SITES=	FESTIVAL
DISTNAME=	festlex_OALD
DIST_SUBDIR=	festival

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Oxford Advanced Learner's pronunciation dictionary for Festival

RUN_DEPENDS=	festival:audio/festival

# Converted from RESTRICTED
LICENSE=	FESTLEX
LICENSE_NAME=	festlex
LICENSE_TEXT=	No commercial use
LICENSE_PERMS=	auto-accept

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

do-install:
	@${MKDIR} ${STAGEDIR}${FHOME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${FHOME}

.include <bsd.port.mk>
