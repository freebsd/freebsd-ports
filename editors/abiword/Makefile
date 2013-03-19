# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/editors/abiword/Makefile,v 1.13 2009/11/10 13:56:18 kwm Exp $

PORTNAME=	abiword
PORTVERSION=	2.8.4
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/%SUBDIR%/${PORTVERSION}/source/
MASTER_SITE_SUBDIR=	abiword
DIST_SUBDIR=	AbiWord

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An open-source, cross-platform WYSIWYG word processor

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt \
		png15:${PORTSDIR}/graphics/png \
		wv-1.2:${PORTSDIR}/textproc/wv \
		jpeg:${PORTSDIR}/graphics/jpeg \
		fribidi:${PORTSDIR}/converters/fribidi \
		psiconv:${PORTSDIR}/converters/psiconv \
		goffice-0.8:${PORTSDIR}/devel/goffice
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSerif.ttf:${PORTSDIR}/x11-fonts/dejavu

USE_GMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USES=		pathfix
USE_GNOME=	libxml2 gtk20 desktopfileutils librsvg2
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--without-gnomevfs --disable-collab-backend-xmpp \
		--disable-collab-backend-sugar
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

ABIVERSION=	2.8
PLIST_SUB+=	ABIVERSION=${ABIVERSION}

MAN1=		abiword.1

OPTIONS_DEFINE=	DEBUG BOOST SPELLCHECK CLIPART TEMPLATES
OPTIONS_DEFAULT=BOOST SPELLCHECK CLIPART TEMPLATES
SPELLCHECK_DESC=	Spell checking support
CLIPART_DESC=		Install clipart
TEMPLATES_DESC=		Install additional templates

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug --enable-symbols
.endif

.if ${PORT_OPTIONS:MBOOST}
CONFIGURE_ARGS+=	--with-boost
LIB_DEPENDS+=		boost_system:${PORTSDIR}/devel/boost-libs
.else
CONFIGURE_ARGS+=	--without-boost
.endif

.if ${PORT_OPTIONS:MSPELLCHECK}
LIB_DEPENDS+=		enchant:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=	--enable-spell
PLIST_SUB+=		DICT=""
.else
CONFIGURE_ARGS+=	--disable-spell
PLIST_SUB+=		DICT="@comment "
.endif

.if ${PORT_OPTIONS:MTEMPLATES}
CONFIGURE_ARGS+=	--enable-templates
PLIST_SUB+=		TEMPLATES=""
.else
CONFIGURE_ARGS+=	--disable-templates
PLIST_SUB+=		TEMPLATES="@comment "
.endif

.if ${PORT_OPTIONS:MCLIPART}
CONFIGURE_ARGS+=	--enable-clipart
PLIST_SUB+=		CLIPART=""
.else
CONFIGURE_ARGS+=	--disable-clipart
PLIST_SUB+=		CLIPART="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/goffice-bits/goffice/app/goffice-app.h \
		${WRKSRC}/src/af/util/xp/ut_go_file.h

post-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}-${ABIVERSION}/plugins
	@-update-desktop-database

.include <bsd.port.mk>
