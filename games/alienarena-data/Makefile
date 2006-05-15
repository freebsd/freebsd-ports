# New ports collection makefile for:	alienarena-data
# Date created:				11 May 2005
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	alienarena
DISTVERSION=	2006.ge
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/~ravage/alienarena2006/ \
		http://cor.planetquake.gamespy.com/codered/files/
PKGNAMESUFFIX=	-data
DISTFILES=	${PORTNAME}-2006ge-x86.run \
		aa2k6updateGE501c-x86.zip

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Alien Arena 2006 (data)

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && \
		${TAIL} -c +8814 ${DISTDIR}/${PORTNAME}-2006ge-x86.run | \
		${TAR} zxf -
	@${TAR} jxf ${WRKDIR}/alienarena-2006ge-data.tar.bz2 -C ${WRKDIR}
	@${UNZIP_CMD} -qod ${WRKDIR} ${DISTDIR}/aa2k6updateGE501c-x86.zip

post-extract:
	@cd ${WRKSRC} && ${RM} arena/game* data1/game*

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -R arena botinfo data1 ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/alienarena.xpm ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
