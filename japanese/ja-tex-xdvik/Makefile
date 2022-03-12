# Created by: Kentaro Inagaki <JBD01226@niftyserve.ne.jp>

PORTNAME=	xdvik
PORTVERSION=	22.87
CATEGORIES=	japanese print
MASTER_SITES=	SF/xdvi/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	ja-tex-
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpaper.so:print/libpaper
RUN_DEPENDS=	tex-dvipsk>=5.995:print/tex-dvipsk

USES=		iconv motif pkgconfig xorg
USE_TEX=	kpathsea texhash texmf web2c
USE_XORG=	ice sm x11 xi xmu xpm xt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir=${LOCALBASE}/share \
		--enable-shared \
		--enable-xi2-scrolling \
		--with-default-dvips-path=${LOCALBASE}/bin/dvips \
		--with-default-gs-lib-path=${LOCALBASE}/lib \
		--with-default-ps2pdf-path=${LOCALBASE}/bin/ps2pdf \
		--with-iconv \
		--with-kpathsea-includes=${LOCALBASE}/include/kpathsea \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-freetype2 \
		--with-system-kpathsea \
		--with-system-libgs \
		--with-system-zlib \
		--with-xdvi-x-toolkit=motif \
		--with-xpm
CONFIGURE_ENV=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CFLAGS+=	-I${LOCALBASE}/include -DHAVE_LIBPAPER -g -O0

CONFLICTS_INSTALL=	*-xdvi ja-xdvik xdvi xdvi-* xdvik

BINARY_ALIAS=	freetype-config=true

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/xdvik

PLIST_SUB=	TEXMFDISTDIR=${TEXMFDISTDIR}
PORTDOCS=	BUGS CHANGES INSTALL README README.CVS README.coding \
		README.config README.cross README.distro README.hacking \
		README.layout README.xdvik README_maintainer TODO

OPTIONS_DEFINE=	DOCS

TEXHASHDIRS=	${TEXMFDISTDIR}

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/fonts/map/xdvi
	${INSTALL_DATA} ${WRKSRC}/xdvi-ptex.map \
	    ${STAGEDIR}${PREFIX}/${TEXMFDISTDIR}/fonts/map/xdvi/xdvi-ptex.map
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME} && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
