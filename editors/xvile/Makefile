# Created by: pgf
# $FreeBSD$

PORTNAME=	xvile
PORTVERSION=	9.8j
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

OPTIONS_DEFINE=	FILTERS ICONV PERL DOCS
OPTIONS_RADIO=	MENUS
OPTIONS_RADIO_MENUS=	MOTIF XAW XAW3D
OPTIONS_DEFAULT=	ICONV
FILTERS_DESC=	Loadable filters
MENUS_DESC=	Support for menus
XAW_DESC=	X Athena Widgets
XAW3D_DESC=	X Athena Widgets with 3D effect

USES=		pkgconfig
USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-imake \
		--enable-fontset \
		--with-xpm \
		--with-pixmapdir=${PREFIX}/share/pixmaps
MAKEFILE=	makefile
MAKE_JOBS_SAFE=	yes

DATADIR=	${PREFIX}/share/vile

MAN1=		xvile.1

CONFLICTS_INSTALL=	vile-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFILTERS}
CONFIGURE_ARGS+=	--with-loadable-filters
PLIST_SUB+=	SO_EXT=".so"
.else
PLIST_SUB+=	SO_EXT=""
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
CONFIGURE_ARGS+=	--with-iconv --with-libiconv-prefix=${LOCALBASE}
PLIST_SUB+=	ICONV=""
.else
BROKEN=		Does not build if ICONV support is disabled
CONFIGURE_ARGS+=	--without-iconv --without-locale
PLIST_SUB+=	ICONV="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=	yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=	PERL=""
.else
PLIST_SUB+=	PERL="@comment "
.endif

.if empty(PORT_OPTIONS:MMOTIF) && empty(PORT_OPTIONS:MXAW) && empty(PORT_OPTIONS:MXAW3D)
CONFIGURE_ARGS+=	--with-screen=x11
.endif

.if ${PORT_OPTIONS:MMOTIF}
USES+=		motif
CONFIGURE_ARGS+=	--with-screen=motif
.endif

.if ${PORT_OPTIONS:MXAW}
USE_XORG+=	xaw
CONFIGURE_ARGS+=	--with-screen=athena
.endif

.if ${PORT_OPTIONS:MXAW3D}
LIB_DEPENDS+=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d
CONFIGURE_ARGS+=	--enable-colored-menus \
			--with-Xaw3d \
			--with-screen=xaw3d
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^DOCDIR|#DOCDIR|' ${WRKSRC}/makefile.in
	@${REINPLACE_CMD} -e \
		's|^#!.*|#!${PERL}|' ${WRKSRC}/perl/vileget

post-install:
	@${MKDIR} ${DATADIR}/macros
	(cd ${WRKSRC}/macros && ${INSTALL_DATA} *.rc ${DATADIR}/macros)
	@${MKDIR} ${DESKTOPDIR}
	(cd ${WRKSRC}/macros && ${INSTALL_DATA} *.desktop ${DESKTOPDIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.doc ${DOCSDIR})
.endif

.include <bsd.port.mk>
