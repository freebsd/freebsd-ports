# New ports collection makefile for:	anjuta
# Date created:				31 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/devel/anjuta/Makefile,v 1.6 2009/04/20 04:42:30 marcus Exp $
#

PORTNAME=	anjuta
PORTVERSION=	2.26.2.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated Development Environment for C and C++

BUILD_DEPENDS=	autogen:${PORTSDIR}/devel/autogen \
		bash:${PORTSDIR}/shells/bash \
		p5-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext \
		neato:${PORTSDIR}/graphics/graphviz
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		gladeui-1.9:${PORTSDIR}/devel/glade3 \
		neon.28:${PORTSDIR}/www/neon28 \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique \
		gdl-1.0:${PORTSDIR}/x11-toolkits/gdl
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		autogen:${PORTSDIR}/devel/autogen \
		neato:${PORTSDIR}/graphics/graphviz \
		p5-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext \
		libtool:${PORTSDIR}/devel/libtool15 \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		exctags:${PORTSDIR}/devel/ctags

USE_BZIP2=	yes
USE_AUTOTOOLS=	autotools:run
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_PERL5=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui vte gtksourceview2 libgda4
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	anjuta-build-basic-autotools-plugin.schemas \
		anjuta-cvs-plugin.schemas \
		anjuta-document-manager.schemas \
		anjuta-editor-scintilla.schemas \
		anjuta-editor-sourceview.schemas \
		anjuta-language-cpp-java.schemas \
		anjuta-message-manager-plugin.schemas \
		anjuta-symbol-db.schemas \
		anjuta-terminal-plugin.schemas \
		anjuta.schemas

MAN1=		anjuta.1 anjuta_launcher.1

OPTIONS=	SVN "Build subversion plugin" off \
		DEVHELP "Build devhelp plugin" on

.include <bsd.port.pre.mk>

.if defined(WITH_SVN)
BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
USE_APACHE=	2.0+

## Test if we got apache 20 or 22.
.if exists(${LOCALBASE}/include/apache22/httpd.h)
APR_CONFIG=${LOCALBASE}/bin/apr-1-config
APU_CONFIG=${LOCALBASE}/bin/apu-1-config
.else
APR_CONFIG=${LOCALBASE}/lib/apache2/apr-config
APU_CONFIG=${LOCALBASE}/lib/apache2/apu-config
.endif
CONFIGURE_ENV+=	APR_CFLAGS="`${APR_CONFIG} --includes`" \
		APR_LIBS="`${APU_CONFIG} --libs`" \
		APR_UTILS_CFLAGS="`${APU_CONFIG} --includes`" \
		APR_UTILS_LIBS="`${APU_CONFIG} --libs`" \

CONFIGURE_ARGS+=--with-subversion-dir=${LOCALBASE}/bin \
		--with-svn-include=${LOCALBASE}/include \
		--with-svn-lib=${LOCALBASE}/lib
PLIST_SUB+=	SVN=""
.else
CONFIGURE_ARGS+=--disable-plugin-subversion
PLIST_SUB+=	SVN="@comment "
.endif

.if defined(WITH_DEVHELP)
LIB_DEPENDS+=	devhelp-1.0:${PORTSDIR}/devel/devhelp
PLIST_SUB+=	DEVHELP=""
.else
CONFIGURE_ARGS+=--disable-plugin-devhelp
# XXX Even if we disable the devhelp plugin it gets build and installed.
# See if versions beyond 2.26.1.0 still do this.
#PLIST_SUB+=	DEVHELP="@comment "
PLIST_SUB+=	DEVHELP=""
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|PKG_PATH|PKG_CONFIG_PATH|g' \
	    	${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|"make|"gmake|g' \
		${WRKSRC}/plugins/build-basic-autotools/plugin.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    	${WRKSRC}/plugins/symbol-db/plugin.h \
		${WRKSRC}/plugins/symbol-db/symbol-db-prefs.h

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
