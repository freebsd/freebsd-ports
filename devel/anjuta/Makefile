# New ports collection makefile for:	anjuta
# Date created:				31 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/anjuta/Makefile,v 1.22 2008/03/11 03:52:48 marcus Exp $
#

PORTNAME=	anjuta
PORTVERSION=	2.4.2
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated Development Environment for C and C++

BUILD_DEPENDS=	autogen:${PORTSDIR}/devel/autogen \
		bash:${PORTSDIR}/shells/bash \
		neato:${PORTSDIR}/graphics/graphviz
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		gbf-1.1:${PORTSDIR}/devel/gnome-build \
		gladeui-1.7:${PORTSDIR}/devel/glade3 \
		neon.28:${PORTSDIR}/www/neon28 \
		devhelp-1.0:${PORTSDIR}/devel/devhelp
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		autogen:${PORTSDIR}/devel/autogen \
		neato:${PORTSDIR}/graphics/graphviz \
		libtool:${PORTSDIR}/devel/libtool15 \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

USE_BZIP2=	yes
USE_AUTOTOOLS=	autotools:run
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeprintui libgnomeui vte \
		gtksourceview2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-plugin-symbol-db
USE_LDCONFIG=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
GCONF_SCHEMAS=	anjuta-build-basic-autotools-plugin.schemas \
		anjuta-cvs-plugin.schemas anjuta-document-manager.schemas \
		anjuta-editor-scintilla.schemas anjuta-language-cpp-java.schemas \
		anjuta-message-manager-plugin.schemas \
		anjuta-editor-sourceview.schemas \
		anjuta-symbol-browser-plugin.schemas \
		anjuta-terminal-plugin.schemas anjuta.schemas

MAN1=		anjuta.1 anjuta_launcher.1

OPTIONS=	SVN "Build subversion plugins" off

.include <bsd.port.pre.mk>

.if defined(WITH_SVN)
BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
USE_APACHE=	2.0+

CONFIGURE_ARGS+=--with-subversion-dir=${LOCALBASE}/bin \
		--with-svn-include=${LOCALBASE}/include \
		--with-svn-lib=${LOCALBASE}/lib \
		--with-apr-config=${LOCALBASE}/bin/apr-1-config \
		--with-apu-config=${LOCALBASE}/bin/apu-1-config
PLIST_SUB+=	SVN=""
.else
CONFIGURE_ARGS+=--disable-plugin-subversion
PLIST_SUB+=	SVN="@comment "
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash| ; \
	    	s|/usr/local|${PREFIX}|' \
	    	${WRKSRC}/global-tags/create_global_tags.sh.in
	@${REINPLACE_CMD} -e 's|PKG_PATH|PKG_CONFIG_PATH|g' \
	    	${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|make|gmake|g' \
		${WRKSRC}/plugins/build-basic-autotools/build-basic-autotools.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog FUTURE INSTALL NEWS README \
	doc/ScintillaDoc.html TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
