# New ports collection makefile for:	edge
# Date created:				2007-11-30
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	edge
PORTVERSION=	1.35
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/EDGE%20Source%20Code/${PORTVERSION} \
		SF/${PORTNAME}/EDGE%20Binaries/${PORTVERSION}:wad
DISTFILES=	Edge-${PORTVERSION}-source${EXTRACT_SUFX} \
		Edge-${PORTVERSION}-linux.tar.gz:wad
EXTRACT_ONLY=	Edge-${PORTVERSION}-source${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DOOM style engine aimed at the Total Conversion developer

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		GLEW.1:${PORTSDIR}/graphics/glew \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/Edge-${PORTVERSION}-source

USE_BZIP2=	yes
USE_SDL=	sdl
USE_GMAKE=	yes
MAKEFILE=	Makefile.linux
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*
PLIST_FILES=	bin/edge %%DMDIR%%/edge.wad
PLIST_DIRSTRY=	%%DMDIR%%

CFLAGS+=	-ffast-math

post-extract:
	@${TAR} -C ${WRKDIR} \
		--exclude "License.txt" \
		--exclude "edge_linux" \
		--exclude "demo-*" \
		--exclude "*.zip" \
		-x -f ${DISTDIR}/Edge-${PORTVERSION}-linux.tar.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 s|^CXX=|CXX?=| ; \
		 s|^CFLAGS=|CFLAGS?=| ; \
		 s|-L$$(LIBDIR)/glew-1.4/lib||' ${WRKSRC}/Makefile.linux
	@${REINPLACE_CMD} -e \
		's|%%DMDIR%%|${DMDIR}|' ${WRKSRC}/src/e_main.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/edge.linux ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${DMDIR}
	${INSTALL_DATA} ${WRKDIR}/Edge-${PORTVERSION}/edge.wad ${DMDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/Edge-${PORTVERSION}/*.txt ${DOCSDIR}
.endif

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
