# New ports collection makefile for:	trophy
# Date created:			22 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $Carpetsmoker: ports/games/trophy/Makefile,v 1.3 2007/08/04 03:36:57 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	trophy
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	games
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
#MASTER_SITE_SUBDIR=	${PORTNAME}
MASTER_SITES=	http://trophy.sourceforge.net/archives/

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	A single player racing game

LIB_DEPENDS=	clanCore-0.8:${PORTSDIR}/devel/clanlib

USE_GMAKE=	yes
MAKEFILE=	Makefile.in
BUILD_WRKSRC=	${WRKSRC}/trophy
CXXFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

post-patch:
	@${REINPLACE_CMD} -e 's/std::sqrt/sqrt/' ${BUILD_WRKSRC}/caimagemanipulation.cpp \
		${BUILD_WRKSRC}/catrophy.cpp ${BUILD_WRKSRC}/camath.cpp
	@${REINPLACE_CMD} -e 's|resources.xml|${DATADIR}/resources.xml|' \
		${BUILD_WRKSRC}/caresources.cpp
	@${REINPLACE_CMD} -e 's|@prefix@|${PREFIX}|; \
		s|@exec_prefix@|$${PREFIX}/bin|; \
		s|@datadir@|${DATADIR}|; \
		s|@bindir@|$${PREFIX}/bin|; \
		s|EXTERN_LIBS =|EXTERN_LIBS = ${PTHREAD_LIBS}|;' \
		${BUILD_WRKSRC}/Makefile.in

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/trophy ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/resources.xml ${DATADIR}
	${CP} -R ${BUILD_WRKSRC}/resources ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/COPYING \
		${WRKSRC}/ChangeLog \
		${WRKSRC}/README \
		${WRKSRC}/TODO \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
