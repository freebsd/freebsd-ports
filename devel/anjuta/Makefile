# New ports collection makefile for:	anjuta
# Date created:				31 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/anjuta/Makefile,v 1.58 2010/04/28 08:11:36 kwm Exp $
#

PORTNAME=	anjuta
PORTVERSION=	2.30.1.0
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated Development Environment for C and C++

BUILD_DEPENDS=	autogen:${PORTSDIR}/devel/autogen \
		bash:${PORTSDIR}/shells/bash \
		p5-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		gladeui-1.9:${PORTSDIR}/devel/glade3 \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique \
		gdl-1.3:${PORTSDIR}/x11-toolkits/gdl
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		autogen:${PORTSDIR}/devel/autogen \
		p5-gettext>=1.05:${PORTSDIR}/devel/p5-Locale-gettext \
		libtool:${PORTSDIR}/devel/libtool22 \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		exctags:${PORTSDIR}/devel/ctags \
		gdb66:${PORTSDIR}/devel/gdb6 \
		yelp:${PORTSDIR}/x11/yelp

USE_BZIP2=	yes
USE_AUTOTOOLS=	autotools:run
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_PERL5=	yes
USE_GNOME=	gnomeprefix gnomehack vte gtksourceview2 libgda4
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-symbol-db-shm=/tmp
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
		preferences.schemas

MAN1=		anjuta.1 anjuta-launcher.1

OPTIONS=	SVN "Build subversion plugin" off \
		DEVHELP "Build devhelp plugin" on

.include <bsd.port.pre.mk>

.if defined(WITH_SVN)
BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
LIB_DEPENDS+=	apr-1.4:${PORTSDIR}/devel/apr1 \
		neon.28:${PORTSDIR}/www/neon28
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
PLIST_SUB+=	SVN=""
.else
CONFIGURE_ARGS+=--disable-plugin-subversion
PLIST_SUB+=	SVN="@comment "
.endif

.if defined(WITH_DEVHELP)
LIB_DEPENDS+=	devhelp-1.1:${PORTSDIR}/devel/devhelp
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog FUTURE INSTALL NEWS README \
	doc/ScintillaDoc.html TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
