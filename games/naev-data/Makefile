# New ports collection makefile for:	naev-data
# Date created:		2009-04-26
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	0.3.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	naev-
DISTNAME=	${PORTNAME:S/^/n/}-${PORTVERSION}
EXTRACT_SUFX=	#
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Naev game data file

PROJECTHOST=	${PKGNAMEPREFIX:S/-//}
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
PLIST_FILES=	share/${PKGNAMEPREFIX:S/-//}/${PORTNAME:S/^/n/}-${PORTVERSION}
PLIST_DIRS=	share/${PKGNAMEPREFIX:S/-//}

do-extract:
	@@${MKDIR} ${WRKSRC}
	@${CP} ${_DISTDIR}/${DISTFILES} ${WRKSRC}

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTFILES} ${DATADIR}

.include <bsd.port.mk>
