# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	edge
PORTVERSION=	1.35
PORTREVISION=	9
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

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libpng.so:graphics/png

USES=		alias gl gmake jpeg sdl tar:bzip2
USE_GL=		glew
USE_SDL=	sdl
MAKEFILE=	Makefile.linux

CFLAGS+=	-ffast-math
WRKSRC=		${WRKDIR}/Edge-${PORTVERSION}-source

PLIST_FILES=	bin/edge %%DMDIR%%/edge.wad
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

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
	${INSTALL_PROGRAM} ${WRKSRC}/edge.linux \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DMDIR}
	${INSTALL_DATA} ${WRKDIR}/Edge-${PORTVERSION}/edge.wad \
		${STAGEDIR}${DMDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/Edge-${PORTVERSION}/*.txt \
		${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../doom-data/Makefile.include"
.include <bsd.port.mk>
