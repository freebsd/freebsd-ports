# New ports collection makefile for:    AbiWord2
# Date created:         22 February 2003
# Whom:                 Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AbiWord2
PORTVERSION=	2.0.10
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.abisource.com/downloads/Version-${PORTVERSION}/lf/
MASTER_SITE_SUBDIR=	abiword
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

WRKSRC=		${WRKDIR}/abiword-${PORTVERSION}/abi

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GNOME=	gnomehier libglade2 libxml2
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
		--disable-peer-config \
		--enable-cmap=no
MAKEFILE=	GNUmakefile

.ifndef(WITHOUT_HELP_DOCS)
PLIST_SUB+=		HELPDOCS:=""
.else
PLIST_SUB+=		HELPDOCS:="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mnautilus2}!="" && ${HAVE_GNOME:Mlibgnomeprintui}!=""
USE_GNOME+=		nautilus2 libgnomeprintui
CONFIGURE_ARGS+=	--enable-gnome
PKGNAMESUFFIX=		-gnome
GNOME_ENABLED=		yes
.endif

.ifndef(WITHOUT_GTKSPELL)
.  if defined(WITH_ENCHANT) || exists(${LOCALBASE}/lib/libenchant.so) && !defined(WITH_ASPELL)
LIB_DEPENDS+=		enchant.2:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=	--disable-pspell
.  elif defined(WITH_ASPELL) || exists(${LOCALBASE}/lib/libaspell.so) && !defined(WITH_ENCHANT)
LIB_DEPENDS+=		aspell.16:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-pspell=${LOCALBASE} \
			--disable-enchant
.  else
LIB_DEPENDS+=		enchant.2:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=	--disable-pspell
.  endif
PLIST_SUB+=		DICT:="@comment "
.else
CONFIGURE_ARGS+=	--disable-enchant --disable-pspell
PLIST_SUB+=		DICT:=""
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "AbiWord2 has the following tunable option(s):"
	@${ECHO_MSG} "	WITHOUT_HELP_DOCS=yes	Disable install the AbiWord HTML Help docs"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "AbiWord2 has the following spell choices: (Enchant is default)"
	@${ECHO_MSG} "	WITH_ASPELL=yes		Enable use of the Aspell dictionary backend (default: auto)"
	@${ECHO_MSG} "	WITH_ENCHANT=yes	Enable use of the Enchant dictionary backend broker (default: auto)"
	@${ECHO_MSG} "	WITHOUT_GTKSPELL=yes	Don't use either Enchant or Aspell, but still"
	@${ECHO_MSG} "				has spell enable and install dictionary."
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|-ansi||g ; s|-pedantic||g' \
		${WRKSRC}/configure
.ifndef(WITHOUT_HELP_DOCS)
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKDIR}/${DISTNAME}/abiword-docs/Makefile
.endif
	@${FIND} ${WRKSRC}/src/config/platforms -name "*.mk" | ${XARGS} \
		${REINPLACE_CMD} 's|-ansi||g ; s|-pedantic||g'
	@${FIND} ${WRKSRC} -name GNUmakefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|@.*PEER.*@||g ; \
		 s|WV_INCLUDES = |#WV_INCLUDES = |g ; \
		 s|[(]libdir[)]/@PACKAGE@|(datadir)/@PACKAGE@|g ; \
		 s|[(]libdir[)]/bonobo/servers|(prefix)/libdata/bonobo/servers|g'

post-install:
.if defined(GNOME_ENABLED)
	@${INSTALL_DATA} ${WRKSRC}/src/pkg/linux/rpm/data/abiword.desktop \
		${PREFIX}/share/gnome/apps/Applications/abiword.desktop
	@${LN} -sf ${PREFIX}/share/AbiSuite-2.0/icons/abiword_48.png \
		${PREFIX}/share/gnome/pixmaps/abiword_48.png
	@${LN} -sf ${PREFIX}/share/AbiSuite-2.0/GNOME_AbiWord_Control_2_0.server \
		${PREFIX}/libdata/bonobo/servers/GNOME_AbiWord_Control_2_0.server
	@${LN} -sf ${PREFIX}/share/AbiSuite-2.0/abi-nautilus-view-file.xml \
		${PREFIX}/share/gnome/gnome-2.0/ui/abi-nautilus-view-file.xml
.endif
.ifndef(WITHOUT_HELP_DOCS)
	@cd ${WRKDIR}/${DISTNAME}/abiword-docs && ${MAKE}
.endif

.include <bsd.port.post.mk>
