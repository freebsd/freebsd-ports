# New ports collection makefile for:    AbiWord2
# Date created:         22 February 2003
# Whom:                 Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abiword
PORTVERSION=	2.3.0
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/%SUBDIR%/${PORTVERSION}/source/
MASTER_SITE_SUBDIR=	abiword
PKGNAMESUFFIX=	-devel
DISTNAME=	abiword-${PORTVERSION}
DIST_SUBDIR=	AbiWord

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An open-source, cross-platform WYSIWYG word processor

# unzip is needed during the installation process
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		png.5:${PORTSDIR}/graphics/png \
		wv-1.0.0:${PORTSDIR}/textproc/wv \
		fribidi.0:${PORTSDIR}/converters/fribidi

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GNOME=	libglade2 libxml2 libgnomeprintui desktopfileutils
WANT_GNOME=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-xft \
		--with-sys-wv \
		--with-popt=${LOCALBASE} \
		--with-zlib=${LOCALBASE} \
		--with-libpng=${LOCALBASE} \
		--with-libiconv=${LOCALBASE} \
		--with-libjpeg-prefix=${LOCALBASE} \
		--disable-peer-config
MAKEFILE=	GNUmakefile

ABIVERSION=	2.4
PLIST_SUB+=	ABIVERSION=${ABIVERSION}
WRKSRC=		${WRKDIR}/abiword-${PORTVERSION}/abi

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug \
			--enable-symbols
.endif

.ifndef(WITHOUT_GTKSPELL)
LIB_DEPENDS+=		enchant.2:${PORTSDIR}/textproc/enchant
PLIST_SUB+=		DICT:="@comment "
.else
CONFIGURE_ARGS+=	--disable-enchant
PLIST_SUB+=		DICT:=""
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=		libgnomeui	 	
CONFIGURE_ARGS+=	--enable-gnome
PKGNAMESUFFIX=		-devel-gnome
#GNOME_ENABLED=		yes
.endif

.if defined(WITH_GUCHARMAP) || exists(${X11BASE}/libdata/pkgconfig/gucharmap.pc)
LIB_DEPENDS+=		gucharmap.4:${PORTSDIR}/deskutils/gucharmap
.else
CONFIGURE_ARGS+=	--enable-cmap=no
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "AbiWord2 has the following tunable option(s):"
	@${ECHO_MSG} "	WITH_DEBUG=yes		Enable debug."
	@${ECHO_MSG} "	WITH_GUCHARMAP=yes	Enable use of Gucharmap as the symbol insertion tool (default: auto)"
	@${ECHO_MSG} "	WITHOUT_GTKSPELL=yes	Don't use Enchant, but still enable spellchecking and install the dictionary."
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|-ansi||g ; s|-pedantic||g' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC}/src/config/platforms -name "*.mk" | ${XARGS} \
		${REINPLACE_CMD} 's|-ansi||g ; s|-pedantic||g'
	@${FIND} ${WRKSRC} -name GNUmakefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|@.*PEER.*@||g ; \
		 s|WV_INCLUDES = |#WV_INCLUDES = |g ; \
		 s|[(]libdir[)]/@PACKAGE@|(datadir)/@PACKAGE@|g ; \
		 s|[(]libdir[)]/bonobo/servers|(prefix)/libdata/bonobo/servers|g'
	@${REINPLACE_CMD} -e 's|(bindir)/ttfadmin.sh|(bindir)/ttfadmin24.sh|g' \
		${WRKSRC}/src/tools/scripts/unix/GNUmakefile.in
	@${REINPLACE_CMD} -e 's|(bindir)/ttftool|(bindir)/ttftool24|g' \
		${WRKSRC}/src/tools/ttftool/unix/GNUmakefile.in

post-install:
	@${MKDIR} ${PREFIX}/lib/AbiWord-${ABIVERSION}/plugins
	@${MKDIR} ${X11BASE}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/abiword.desktop \
		${X11BASE}/share/applications/abiword24.desktop
	@${MKDIR} ${X11BASE}/share/pixmaps
	@${LN} -sf ${PREFIX}/share/AbiSuite-${ABIVERSION}/icons/abiword_48.png \
		${X11BASE}/share/pixmaps/abiword24_48.png
#	@${INSTALL_DATA} ${WRKDIR}/abiword-${PORTVERSION}/abidistfiles/GNOME_AbiWord_Control_${ABIVERSION:S/./_/}.server \
#		${X11BASE}/libdata/bonobo/servers/
#	@${INSTALL_DATA} ${WRKDIR}/abiword-${PORTVERSION}/abidistfiles/abi-nautilus-view-file.xml \
#		${X11BASE}/share/gnome/gnome-2.0/ui/
	@-update-desktop-database

.include <bsd.port.post.mk>
