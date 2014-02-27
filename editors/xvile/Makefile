# Created by: pgf
# $FreeBSD$

PORTNAME=	xvile
PORTVERSION=	9.8l
CATEGORIES=	editors
MASTER_SITES=	ftp://dickey.his.com/vile/current/ \
		ftp://invisible-island.net/vile/current/
DISTNAME=	vile-${PORTVERSION}
EXTRACT_SUFX=	.tgz

PATCH_SITES=	${MASTER_SITES:S,vile/current/,vile/patches/,g}
PATCHFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VI Like Emacs -- X11 version

LICENSE=	GPLv2

BUILD_DEPENDS=	reflex:${PORTSDIR}/textproc/reflex

USES=		pkgconfig shebangfix
SHEBANG_FILES=	macros/lxvile macros/lxvile-fonts perl/vileget
USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-imake \
		--enable-fontset \
		--with-xpm \
		--with-pixmapdir=${PREFIX}/share/pixmaps
MAKEFILE=	makefile

DATADIR=	${PREFIX}/share/vile

CONFLICTS_INSTALL=	vile-[0-9]*

OPTIONS_DEFINE=		DOCS FILTERS ICONV PERL
OPTIONS_RADIO=		MENUS
OPTIONS_RADIO_MENUS=	MOTIF XAW XAW3D
OPTIONS_DEFAULT=	ICONV
OPTIONS_SUB=		yes

FILTERS_DESC=		Loadable filters
FILTERS_CONFIGURE_WITH=	loadable-filters
ICONV_USES=		iconv
ICONV_CONFIGURE_ON=	--with-iconv ${ICONV_CONFIGURE_ARG}
ICONV_CONFIGURE_OFF=	--without-iconv --without-locale
MENUS_DESC=		Support for menus
MOTIF_USE=		MOTIF=yes
MOTIF_CONFIGURE_ON=	--with-screen=motif
PERL_USES=		perl5
PERL_CONFIGURE_WITH=	perl
XAW_DESC=		X Athena Widgets
XAW_USE=		XORG=xaw
XAW_CONFIGURE_ON=	--with-screen=athena
XAW3D_DESC=		X Athena Widgets with 3D effect
XAW3D_LIB_DEPENDS=	libXaw3d.so:${PORTSDIR}/x11-toolkits/Xaw3d
XAW3D_CONFIGURE_ON=	--enable-colored-menus \
			--with-Xaw3d \
			--with-screen=xaw3d

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFILTERS}
PLIST_SUB+=	SO_EXT=".so"
.else
PLIST_SUB+=	SO_EXT=""
.endif

.if empty(PORT_OPTIONS:MICONV)
BROKEN=		Does not build if ICONV support is disabled
.endif

.if empty(PORT_OPTIONS:MMOTIF) && empty(PORT_OPTIONS:MXAW) && empty(PORT_OPTIONS:MXAW3D)
CONFIGURE_ARGS+=	--with-screen=x11
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^DOCDIR|#DOCDIR|' ${WRKSRC}/makefile.in
	@${REINPLACE_CMD} -e \
		'/^Icons/s|=.*|=${PREFIX}/share/pixmaps/vile_48x48.png|' \
		${WRKSRC}/macros/*.desktop

post-install:
	(cd ${WRKSRC}/icons && ${INSTALL_DATA} vile_48x48.png \
		${STAGEDIR}${PREFIX}/share/pixmaps)
	(cd ${WRKSRC}/macros && ${INSTALL_DATA} *.desktop \
		${STAGEDIR}${DESKTOPDIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}/macros
	(cd ${WRKSRC}/macros && ${INSTALL_DATA} *.rc \
		${STAGEDIR}${DATADIR}/macros)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.doc \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html \
		${STAGEDIR}${DOCSDIR}/html)

.include <bsd.port.mk>
