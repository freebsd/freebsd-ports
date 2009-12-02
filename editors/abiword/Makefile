# New ports collection makefile for:    AbiWord2
# Date created:         22 February 2003
# Whom:                 Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/editors/abiword/Makefile,v 1.13 2009/11/10 13:56:18 kwm Exp $
#

PORTNAME=	abiword
PORTVERSION=	2.8.1
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/%SUBDIR%/${PORTVERSION}/source/
MASTER_SITE_SUBDIR=	abiword
DIST_SUBDIR=	AbiWord

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An open-source, cross-platform WYSIWYG word processor

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		png.5:${PORTSDIR}/graphics/png \
		wv-1.2:${PORTSDIR}/textproc/wv \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		fribidi.3:${PORTSDIR}/converters/fribidi \
		goffice-0.8.7:${PORTSDIR}/devel/goffice
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSerif.ttf:${PORTSDIR}/x11-fonts/dejavu

USE_GMAKE=	yes
USE_ICONV=	yes
USE_GNOME=	gnomehack libxml2 gtk20 desktopfileutils librsvg2
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-gnomevfs --disable-collab-backend-xmpp \
		--disable-collab-backend-sugar
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

ABIVERSION=	2.8
PLIST_SUB+=	ABIVERSION=${ABIVERSION}

OPTIONS=	DEBUG "Enable debug" off \
		BOOST "Build with boost" on \
		GUCHARMAP "Use Gucharmap as the symbol insertion tool" on \
		SPELLCHECK "Enable spell checking support" on \
		CLIPART "Install clipart" on \
		TEMPLATES "Install additional templates" on

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug --enable-symbols
.endif

.if defined(WITH_BOOST)
CONFIGURE_ARGS+=	--with-boost
LIB_DEPENDS+=		boost_system.4:${PORTSDIR}/devel/boost-libs
.else
CONFIGURE_ARGS+=	--without-boost
.endif

.if defined(WITH_SPELLCHECK)
LIB_DEPENDS+=		enchant.1:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=	--enable-spell
PLIST_SUB+=		DICT=""
.else
CONFIGURE_ARGS+=	--disable-spell
PLIST_SUB+=		DICT="@comment "
.endif

.if defined(WITH_GUCHARMAP)
LIB_DEPENDS+=		gucharmap.7:${PORTSDIR}/deskutils/gucharmap
CONFIGURE_ARGS+=	--with-gucharmap
.else
CONFIGURE_ARGS+=	--without-gucharmap
.endif

.if defined(WITH_TEMPLATES)
CONFIGURE_ARGS+=	--enable-templates
PLIST_SUB+=		TEMPLATES=""
.else
CONFIGURE_ARGS+=	--disable-templates
PLIST_SUB+=		TEMPLATES="@comment "
.endif

.if defined(WITH_CLIPART)
CONFIGURE_ARGS+=	--enable-clipart
PLIST_SUB+=		CLIPART=""
.else
CONFIGURE_ARGS+=	--disable-clipart
PLIST_SUB+=		CLIPART="@comment "
.endif

post-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}-${ABIVERSION}/plugins
	@-update-desktop-database
	@${MKDIR} ${PREFIX}/share/mime-info/packages
	@-update-mime-database ${PREFIX}/share/mime-info

.include <bsd.port.post.mk>
