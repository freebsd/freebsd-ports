# New ports collection makefile for:    AbiWord2
# Date created:         22 February 2003
# Whom:                 Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AbiWord2
PORTVERSION=	1.1.4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.abisource.com/downloads/Version-${PORTVERSION}/lf/
MASTER_SITE_SUBDIR=	abiword
DISTNAME=	abiword-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An open-source, cross-platform WYSIWYG word processor

# unzip is needed during the installation process
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		iconv.3:${PORTSDIR}/converters/libiconv \
		glade-2.0.0:${PORTSDIR}/devel/libglade2 \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		fribidi.0:${PORTSDIR}/converters/fribidi \
		aspell.15:${PORTSDIR}/textproc/aspell

DIST_SUBDIR=	AbiWord

WRKSRC=		${WRKDIR}/abiword-${PORTVERSION}/abi

USE_X_PREFIX=	yes
USE_AUTOMAKE=	yes
USE_AUTOMAKE_VER=14
USE_AUTOCONF_VER=213
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehier
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -liconv"
CONFIGURE_ARGS=	--enable-xft
MAKEFILE=	GNUmakefile

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/wv.h)
BROKEN=	"This port cannot be built when textproc/wv is installed because of a header conflict.  Please remove textproc/wv, and resume the build.  If textproc/wv is no longer installed, please remove ${LOCALBASE}/include/wv.h, and resume the AbiWord2 build"
.endif

.if defined(WITH_GNOME) || \
	( exists(${X11BASE}/libdata/pkgconfig/libnautilus.pc) && \
		exists(${X11BASE}/libdata/pkgconfig/gal-2.0.pc) )
LIB_DEPENDS+=		nautilus.2:${PORTSDIR}/x11-fm/nautilus2 \
			gal-2.0.1:${PORTSDIR}/x11-toolkits/gal2
CONFIGURE_ARGS+=	--enable-gnome
PLIST_SUB+=		GNOME:=""
PKGNAMESUFFIX=		-gnome
.else
PLIST_SUB+=		GNOME:="@comment "
.endif

.if defined(WITH_GUCHARMAP) || exists(${X11BASE}/libdata/pkgconfig/gucharmap.pc)
LIB_DEPENDS+=		gucharmap.1:${PORTSDIR}/misc/gucharmap
.else
CONFIGURE_ARGS+=	--disable-gucharmap
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "AbiWord2 has the following tunable option(s):"
	@${ECHO_MSG} "	WITH_GUCHARMAP=yes	Enable use of Gucharmap as the symbol insertion tool (default: auto)"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|%%AUTOMAKE%%|${AUTOMAKE}|g ; \
		s|%%ACLOCAL%%|${ACLOCAL}|g ; \
		s|%%AUTOCONF%%|${AUTOCONF}|g' ${WRKSRC}/autogen.sh

pre-configure:
	@cd ${WRKSRC} && ${TOUCH} NEWS README AUTHORS ChangeLog INSTALL
	@cd ${WRKSRC}/ac-helpers && ${RM} -f install-sh mkinstalldirs missing
	@${RM} -f ${WRKSRC}/configure.ac
	@cd ${WRKSRC} && ./autogen.sh && ${TRUE}
	@${FIND} ${WRKSRC} -name GNUmakefile.in | xargs ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/@PACKAGE@|(datadir)/@PACKAGE@|g ; \
		 s|@DEFS@|-I${WRKSRC}/../libiconv/include @DEFS@|g' && ${TRUE}

post-install:
	@${CAT} ${PKGMESSAGE}
	@${INSTALL_DATA} ${WRKSRC}/src/pkg/linux/rpm/data/abiword.desktop \
		${PREFIX}/share/gnome/apps/Applications/abiword.desktop
	@${LN} -sf ${PREFIX}/share/AbiSuite-2.0/icons/abiword_48.png \
		${PREFIX}/share/gnome/pixmaps/abiword_48.png

.include <bsd.port.post.mk>
