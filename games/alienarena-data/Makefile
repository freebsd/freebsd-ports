# New ports collection makefile for:	alienarena-data
# Date created:				11 May 2005
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	alienarena
PORTVERSION=	2007
CATEGORIES=	games
MASTER_SITES=	http://www.alienarena.org/downloads/ \
		http://www.forsakenweb.com/gamepage/loaders/games/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}-${PORTVERSION}-x86
EXTRACT_SUFX=	.run

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Alien Arena 2006 (data)

NO_BUILD=	yes
NO_PACKAGE=	Package will be 163MB, set FORCE_PACKAGE if you want it
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && \
		${TAIL} +377 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -
	@${TAR} jxf ${WRKDIR}/${PORTNAME}${PORTVERSION}-data.tar.bz2 \
		-C ${WRKDIR}

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
