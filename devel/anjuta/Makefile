# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/anjuta/Makefile,v 1.72 2012/12/13 20:33:05 kwm Exp $

PORTNAME=	anjuta
PORTVERSION=	2.32.1.1
PORTREVISION=	14
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated Development Environment for C and C++

BUILD_DEPENDS=	autogen:${PORTSDIR}/devel/autogen \
		bash:${PORTSDIR}/shells/bash \
		p5-Locale-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libgladeui-1.so:${PORTSDIR}/devel/glade3 \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libgdl-1.so:${PORTSDIR}/x11-toolkits/gdl
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		autogen:${PORTSDIR}/devel/autogen \
		${LOCALBASE}/share/autotools:${PORTSDIR}/devel/autotools \
		p5-Locale-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		exctags:${PORTSDIR}/devel/ctags \
		gdb66:${PORTSDIR}/devel/gdb66 \
		yelp:${PORTSDIR}/x11/yelp

CONFLICTS=	anjuta-3.[0-9]*

USES=		desktop-file-utils gmake gettext libtool pathfix \
		perl5 pkgconfig shared-mime-info shebangfix tar:bzip2
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USE_PYTHON=	yes
USE_GNOME=	gnomeprefix vte gtksourceview2 libgda4
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-symbol-db-shm=/tmp \
		--disable-vala \
		--disable-graphviz \
		--enable-introspection=no
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	anjuta-build-basic-autotools-plugin.schemas \
		anjuta-cvs-plugin.schemas \
		anjuta-debug-manager.schemas \
		anjuta-document-manager.schemas \
		anjuta-editor-sourceview.schemas \
		anjuta-language-cpp-java.schemas \
		anjuta-message-manager-plugin.schemas \
		anjuta-symbol-db.schemas \
		anjuta-terminal-plugin.schemas \
		file-manager.schemas \
		preferences.schemas \
		python-plugin-properties.schemas
SHEBANG_FILES=	scripts/builder2schema.pl \
		plugins/gbf-am/gbf-am-parse.in \
		plugins/gbf-mkfile/gbf-mkfile-parse.in \
		plugins/tools/scripts/*.pl

OPTIONS_DEFINE=	SVN DEVHELP DOCS
OPTIONS_DEFAULT=DEVHELP
DEVHELP_DESC=	Devhelp support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSVN}
BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
LIB_DEPENDS+=	libapr-1.so:${PORTSDIR}/devel/apr1
LIB_DEPENDS+=	libneon.so:${PORTSDIR}/www/neon29
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
PLIST_SUB+=	SVN=""
.else
CONFIGURE_ARGS+=--disable-plugin-subversion
PLIST_SUB+=	SVN="@comment "
.endif

.if ${PORT_OPTIONS:MDEVHELP}
LIB_DEPENDS+=	libdevhelp-2.so:${PORTSDIR}/devel/devhelp
PLIST_SUB+=	DEVHELP=""
.else
CONFIGURE_ARGS+=--disable-plugin-devhelp
# XXX Even if we disable the devhelp plugin it gets build and installed.
# See if versions beyond 2.26.1.0 still do this.
#PLIST_SUB+=	DEVHELP="@comment "
PLIST_SUB+=	DEVHELP=""
.endif

post-patch:
	@${RM} ${WRKSRC}/plugins/debug-manager/anjuta-debug-manager.schemas

post-configure:
	@${REINPLACE_CMD} -e 's|"make|"gmake|g' \
		${WRKSRC}/plugins/build-basic-autotools/plugin.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    	${WRKSRC}/plugins/symbol-db/plugin.h \
		${WRKSRC}/plugins/symbol-db/symbol-db-prefs.h

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog FUTURE INSTALL NEWS README \
	doc/ScintillaDoc.html TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
