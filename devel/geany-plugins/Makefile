# New ports collection Makefile for:	geany-plugins
# Date Created:				24 May 2010
# Whom:					Aldis Berjoza <aldis@bsdroot.lv>
#
# $FreeBSD$
#

PORTNAME=	geany-plugins
PORTVERSION=	0.18
CATEGORIES=	devel
MASTER_SITES=	http://plugins.geany.org/geany-plugins/

MAINTAINER=	aldis@bsdroot.lv
COMMENT=	Plugins for lightwidth editor - geany

BUILD_DEPENDS=	geany:${PORTSDIR}/devel/geany
RUN_DEPENDS=	geany:${PORTSDIR}/devel/geany

USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_BZIP2=	yes
USE_PYTHON_BUILD=	2.6+

OPTIONS=	GEANY_ADDONS		"ADDONS" on \
		GEANY_GEANYDOC		"GEANYDOC" on \
		GEANY_GEANYGDB		"GDB support" on \
		GEANY_GEANYLATEX	"Improve work with LaTeX" on \
		GEANY_GEANYLIPSUM	"GEANYLIPSUM" on \
		GEANY_GEANYLUA		"LUA support" on \
		GEANY_GEANYPRJ		"Alternative project management" on \
		GEANY_GEANYSENDMAIL	"Sending mail from geany" on \
		GEANY_GEANYVC		"Version-control systems support" on \
		GEANY_SHIFTCOLUMN	"SHIFTCOLUMN" on \
		GEANY_SPELLCHECK	"Spellchecker support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GEANY_GEANYDOC)
BUILD_PLUGINS+=	,geanydoc
PLIST_FILES+=	lib/geany/geanydoc.so
.endif

.if !defined(WITHOUT_GEANY_ADDONS)
BUILD_PLUGINS+=	,addons
PLIST_FILES+=	lib/geany/addons.so
.endif

.if !defined(WITHOUT_GEANY_GEANYGDB)
BUILD_PLUGINS+=	,geanygdb
PLIST_FILES+=	lib/geany/geanygdb.so
.endif

.if !defined(WITHOUT_GEANY_GEANYLATEX)
BUILD_PLUGINS+=	,geanylatex
PLIST_FILES+=	lib/geany/geanylatex.so
.endif

.if !defined(WITHOUT_GEANY_GEANYLIPSUM)
BUILD_PLUGINS+=	,geanylipsum
PLIST_FILES+=	lib/geany/geanylipsum.so
.endif

.if !defined(WITHOUT_GEANY_GEANYLUA)
BUILD_PLUGINS+=	,geanylua
USE_LUA=	5.1
PLIST_FILES+=	lib/geany/geanylua.so \
		lib/geany-plugins/geanylua/libgeanylua.so \
		share/doc/geany-plugins/geanylua/geanylua-input.html \
		share/doc/geany-plugins/geanylua/geanylua-ref.html \
		share/doc/geany-plugins/geanylua/geanylua-index.html \
		share/doc/geany-plugins/geanylua/geanylua-intro.html \
		share/doc/geany-plugins/geanylua/geanylua-keys.html \
		share/doc/geany-plugins/geanylua/geanylua-keyfile.html \
		share/doc/geany-plugins/geanylua/luarefv51.html \
		share/geany-plugins/geanylua/dialogs/complex-dialog.lua \
		share/geany-plugins/geanylua/dialogs/basic-dialogs.lua \
		share/geany-plugins/geanylua/edit/select-block.lua \
		share/geany-plugins/geanylua/edit/proper-case.lua \
		share/geany-plugins/geanylua/edit/right-trim.lua \
		share/geany-plugins/geanylua/edit/calculator.lua \
		share/geany-plugins/geanylua/edit/lua-replace.lua \
		share/geany-plugins/geanylua/edit/reverse.lua \
		share/geany-plugins/geanylua/info/show-filename.lua \
		share/geany-plugins/geanylua/info/about.lua \
		share/geany-plugins/geanylua/info/list-open-files.lua \
		share/geany-plugins/geanylua/info/file-informa\tion.lua \
		share/geany-plugins/geanylua/info/app-information.lua \
		share/geany-plugins/geanylua/scripting/show-examples.lua \
		share/geany-plugins/geanylua/scripting/open-script.lua \
		share/geany-plugins/geanylua/scripting/help.lua \
		share/geany-plugins/geanylua/scripting/rebuild-menu.lua \
		share/geany-plugins/geanylua/work/03.install-test-script.lua \
		share/geany-plugins/geanylua/work/02.run-test-script.lua \
		share/geany-plugins/geanylua/work/01.edit-test-script.lua
PLIST_DIRS+=	lib/geany-plugins/geanylua \
		lib/geany-plugins \
		share/doc/geany-plugins/geanylua \
		share/doc/geany-plugins \
		share/geany-plugins/geanylua/dialogs \
		share/geany-plugins/geanylua/edit \
		share/geany-plugins/geanylua/info \
		share/geany-plugins/geanylua/scripting \
		share/geany-plugins/geanylua/work \
		share/geany-plugins/geanylua \
		share/geany-plugins
.endif

.if !defined(WITHOUT_GEANY_GEANYPRJ)
BUILD_PLUGINS+=	,geanyprj
PLIST_FILES+=	lib/geany/geanyprj.so
.endif

.if !defined(WITHOUT_GEANY_GEANYVC)
BUILD_PLUGINS+=	,geanyvc
LIB_DEPENDS+=	gtkspell:${PORTSDIR}/textproc/gtkspell
PLIST_FILES+=	lib/geany/geanyvc.so
.endif

.if !defined(WITHOUT_GEANY_GEANYSENDMAIL)
BUILD_PLUGINS+=	,geanysendmail
PLIST_FILES+=	lib/geany/geanysendmail.so
.endif

.if !defined(WITHOUT_GEANY_SHIFTCOLUMN)
BUILD_PLUGINS+=	,shiftcolumn
PLIST_FILES+=	lib/geany/shiftcolumn.so
.endif

.if !defined(WITHOUT_GEANY_SPELLCHECK)
BUILD_PLUGINS+=	,spellcheck
LIBDEPENS+=	enchant:${PORTSDIR}/textproc/enchant
PLIST_FILES+=	lib/geany/spellcheck.so
.endif

.if !defined(BUILD_PLUGINS)
IGNORE=	no plugins selected
.endif

.if !defined(WITHOUT_NLS)
PLIST_FILES+=	share/locale/be/LC_MESSAGES/geany-plugins.mo \
		share/locale/de/LC_MESSAGES/geany-plugins.mo \
		share/locale/es/LC_MESSAGES/geany-plugins.mo \
		share/locale/pt_PT/LC_MESSAGES/geany-plugins.mo \
		share/locale/ru/LC_MESSAGES/geany-plugins.mo \
		share/locale/tr/LC_MESSAGES/geany-plugins.mo
.endif

do-configure:
	BUILD_PLUGINS=$(${ECHO} ${BUILD_PLUGINS} | ${SED} -e 's/^,//')
	${WRKSRC}/waf configure --enable-plugins="${BUILD_PLUGINS}" -b ${WRKSRC}/_build_

do-install:
.if !defined(WITHOUT_GEANY_GEANYDOC)
	${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/geanydoc.so ${PREFIX}/lib/geany/geanydoc.so
.endif
.if !defined(WITHOUT_GEANY_ADDONS)
	${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/addons.so ${PREFIX}/lib/geany/addons.so
.endif
.if !defined(WITHOUT_GEANY_GEANYGDB)
	${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/geanygdb.so ${PREFIX}/lib/geany/geanygdb.so
.endif
.if !defined(WITHOUT_GEANY_GEANYLATEX)
	${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/geanylatex.so ${PREFIX}/lib/geany/geanylatex.so
.endif
.if !defined(WITHOUT_GEANY_GEANYLIPSUM)
	${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/geanylipsum.so ${PREFIX}/lib/geany/geanylipsum.so
.endif
.if !defined(WITHOUT_GEANY_GEANYLUA)
	${MKDIR} ${PREFIX}/lib/geany-plugins/geanylua
	${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/libgeanylua.so ${PREFIX}/lib/geany-plugins/geanylua/libgeanylua.so
	${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/geanylua.so ${PREFIX}/lib/geany/geanylua.so
	(cd ${WRKSRC}/geanylua/examples/ && ${COPYTREE_SHARE} \* ${PREFIX}/share/geany-plugins/geanylua/ "! -name Makefile.in -and ! -name Makefile.am")
	(cd ${WRKSRC}/geanylua/docs/ && ${COPYTREE_SHARE} \* ${PREFIX}/share/doc/geany-plugins/geanylua/ "! -name Makefile.in -and ! -name Makefile.am")
.endif
.if !defined(WITHOUT_GEANY_GEANYPRJ)
	${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/geanyprj.so ${PREFIX}/lib/geany/geanyprj.so
.endif
.if !defined(WITHOUT_GEANY_GEANYVC)
	${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/geanyvc.so ${PREFIX}/lib/geany/geanyvc.so
.endif
.if !defined(WITHOUT_GEANY_GEANYSENDMAIL)
	${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/geanysendmail.so ${PREFIX}/lib/geany/geanysendmail.so
.endif
.if !defined(WITHOUT_GEANY_SHIFTCOLUMN)
	${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/shiftcolumn.so ${PREFIX}/lib/geany/shiftcolumn.so
.endif
.if !defined(WITHOUT_GEANY_SPELLCHECK)
	${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/spellcheck.so ${PREFIX}/lib/geany/spellcheck.so
.endif
.if !defined(WITHOUT_NLS)
	${INSTALL_DATA} ${WRKSRC}/_build_/default/po/be.mo ${PREFIX}/share/locale/be/LC_MESSAGES/geany-plugins.mo
	${INSTALL_DATA} ${WRKSRC}/_build_/default/po/de.mo ${PREFIX}/share/locale/de/LC_MESSAGES/geany-plugins.mo
	${INSTALL_DATA} ${WRKSRC}/_build_/default/po/es.mo ${PREFIX}/share/locale/es/LC_MESSAGES/geany-plugins.mo
	${INSTALL_DATA} ${WRKSRC}/_build_/default/po/pt_PT.mo ${PREFIX}/share/locale/pt_PT/LC_MESSAGES/geany-plugins.mo
	${INSTALL_DATA} ${WRKSRC}/_build_/default/po/ru.mo ${PREFIX}/share/locale/ru/LC_MESSAGES/geany-plugins.mo
	${INSTALL_DATA} ${WRKSRC}/_build_/default/po/tr.mo ${PREFIX}/share/locale/tr/LC_MESSAGES/geany-plugins.mo
.endif

.include <bsd.port.post.mk>
