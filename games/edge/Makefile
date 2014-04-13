# Created by: alepulver
# $FreeBSD$

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

LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/Edge-${PORTVERSION}-source

USES=		gmake tar:bzip2
USE_SDL=	sdl
MAKEFILE=	Makefile.linux

PORTDOCS=	*
PLIST_FILES=	bin/edge %%DMDIR%%/edge.wad
PLIST_DIRSTRY=	%%DMDIR%%

CFLAGS+=	-ffast-math

DEFINE_OPTIONS=	DOCS

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
	${INSTALL_PROGRAM} ${WRKSRC}/edge.linux ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DMDIR}
	${INSTALL_DATA} ${WRKDIR}/Edge-${PORTVERSION}/edge.wad ${STAGEDIR}${DMDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/Edge-${PORTVERSION}/*.txt ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
