# New ports collection makefile for:	alienarena-data
# Date created:				11 May 2005
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	alienarena
DISTVERSION=	2006.ue
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/~ravage/alienarena2006/ \
		http://cor.planetquake.gamespy.com/codered/files/ \
		http://www.forsakenweb.com/gamepage/loaders/games/
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}-${DISTVERSION:S/.//}-x86
EXTRACT_SUFX=	.run

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Alien Arena 2006 (data)

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_PACKAGE=	Package will be 163MB, set FORCE_PACKAGE if you want it

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not extract (gzip error)
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && \
		${TAIL} +377 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -
	@${TAR} zxf ${WRKDIR}/${PORTNAME}-${DISTVERSION:S/.//}-data.tar.bz2 \
		-C ${WRKDIR}

post-extract:
	@cd ${WRKSRC}/data1/levelshots && \
		${MV} ctf-strongholdl.txt ctf-stronghold.txt

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -R arena botinfo data1 ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/alienarena.xpm ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
