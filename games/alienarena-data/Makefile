# New ports collection makefile for:	alienarena-data
# Date created:				11 May 2005
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	alienarena
PORTVERSION=	2007.604
CATEGORIES=	games
MASTER_SITES=	http://cor.planetquake.gamespy.com/codered/files/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}2007-linux20070225-x86

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Alien Arena 2006 (data)

USE_ZIP=	yes
NO_BUILD=	yes
NO_PACKAGE=	Package will be 185MB, set FORCE_PACKAGE if you want it
WRKSRC=		${WRKDIR}/${DISTNAME:C/-linux.*//}

.include <bsd.port.pre.mk>

post-extract:
	@cd ${WRKSRC}/arena && ${RM} *.dll *.so
	@cd ${WRKSRC}/data1 && ${RM} *.dll *.so

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -R arena botinfo data1 ${DATADIR}
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/alienarena.xpm ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
