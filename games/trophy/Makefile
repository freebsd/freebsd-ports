# New ports collection makefile for:	trophy
# Date created:			22 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		trophy
PORTVERSION=		1.1.3
PORTREVISION=	1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-${PORTVERSION}-src

MAINTAINER=		jylefort@brutele.be
COMMENT=		A single player racing game

LIB_DEPENDS=		clanCore.2:${PORTSDIR}/devel/clanlib

USE_X_PREFIX=		yes
USE_GMAKE=		yes
BUILD_WRKSRC=		${WRKSRC}/trophy

MAKE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
			PTHREAD_LIBS=${PTHREAD_LIBS}

post-extract:
	@${FIND} ${BUILD_WRKSRC}/resources -name .cvsignore -exec ${RM} -f {} \;

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/trophy ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/resources.scr ${DATADIR}
	${CP} -R ${BUILD_WRKSRC}/resources ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/ChangeLog \
		${WRKSRC}/ChangeLog.old \
		${WRKSRC}/README \
		${WRKSRC}/TODO \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
