# New ports collection Makefile for:	geany-plugins
# Date Created:				24 May 2010
# Whom:					Aldis Berjoza <aldis@bsdroot.lv>
#
# $FreeBSD$
#

PORTNAME=	geany-plugins
PORTVERSION=	0.19
CATEGORIES=	devel
MASTER_SITES=	http://plugins.geany.org/geany-plugins/

MAINTAINER=	ar@null.lv
COMMENT=	Plugins for lightwidth editor - geany

BUILD_DEPENDS=	geany:${PORTSDIR}/devel/geany
RUN_DEPENDS=	geany:${PORTSDIR}/devel/geany

USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_BZIP2=	yes
USE_PYTHON_BUILD=	2.6+

OPTIONS=	GEANY_ADDONS		"ADDONS" on \
		GEANY_GEANYDOC		"GEANYDOC" on \
		GEANY_GEANYGDB		"GDB support (broken)" off \
		GEANY_GEANYLATEX	"Improve work with LaTeX" on \
		GEANY_GEANYLIPSUM	"GEANYLIPSUM" on \
		GEANY_GEANYLUA		"LUA support" on \
		GEANY_GEANYPRJ		"Alternative project management" on \
		GEANY_GEANYSENDMAIL	"Sending mail from geany" on \
		GEANY_GEANYVC		"Version-control systems support" on \
		GEANY_SHIFTCOLUMN	"SHIFTCOLUMN" on \
		GEANY_SPELLCHECK	"Spellchecker support" on \
		GEANY_CODENAV		"Siwtch between header and source" on \
		GEANY_INSERTNUM		"geanyinsertnum" on \
		GEANY_GEANYEXTRASEL	"geanyextrasel" on \
		GEANY_TREEBROWSER	"Tree Browser" on \
		GEANY_PRETTYPRINTER	"Pretty-printer" on

.include <bsd.port.pre.mk>
PLUGINS=

.if !defined(WITHOUT_GEANY_TREEBROWSER)
BUILD_PLUGINS+=	,treebrowser
PLUGINS+=	treebrowser.so
.endif

.if !defined(WITHOUT_GEANY_CODENAV)
BUILD_PLUGINS+=	,codenav
PLUGINS+=	codenav.so
.endif

.if !defined(WITHOUT_GEANY_INSERTNUM)
BUILD_PLUGINS+=	,geanyinsertnum
PLUGINS+=	geanyinsertnum.so
.endif

.if !defined(WITHOUT_GEANY_GEANYEXTRASEL)
BUILD_PLUGINS+=	,geanyextrasel
PLUGINS+=	geanyextrasel.so
.endif

.if !defined(WITHOUT_GEANY_PRETTYPRINTER)
BUILD_PLUGINS+=	,pretty-printer
PLUGINS+=	pretty-printer.so
.endif

.if !defined(WITHOUT_GEANY_GEANYDOC)
BUILD_PLUGINS+=	,geanydoc
PLUGINS+=	geanydoc.so
.endif

.if !defined(WITHOUT_GEANY_ADDONS)
BUILD_PLUGINS+=	,addons
PLUGINS+=	addons.so
.endif

.if !defined(WITHOUT_GEANY_GEANYGDB)
# handle geanygdb manually
BROKEN=	geanygdb plugins doesn't work
BUILD_PLUGINS+=	,geanygdb
PLIST_FILES+=	lib/geany/geanygdb.so \
		libexec/geany-plugins/geanygdb/ttyhelper
.endif

.if !defined(WITHOUT_GEANY_GEANYLATEX)
BUILD_PLUGINS+=	,geanylatex
PLUGINS+=	geanylatex.so
.endif

.if !defined(WITHOUT_GEANY_GEANYLIPSUM)
BUILD_PLUGINS+=	,geanylipsum
PLUGINS+=	geanylipsum.so
.endif

.if !defined(WITHOUT_GEANY_GEANYLUA)
# I will handle geanulua manually
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
PLUGINS+=	geanyprj.so
.endif

.if !defined(WITHOUT_GEANY_GEANYVC)
BUILD_PLUGINS+=	,geanyvc
LIB_DEPENDS+=	gtkspell:${PORTSDIR}/textproc/gtkspell
PLUGINS+=	geanyvc.so
.endif

.if !defined(WITHOUT_GEANY_GEANYSENDMAIL)
BUILD_PLUGINS+=	,geanysendmail
PLUGINS+=	geanysendmail.so
.endif

.if !defined(WITHOUT_GEANY_SHIFTCOLUMN)
BUILD_PLUGINS+=	,shiftcolumn
PLUGINS+=	shiftcolumn.so
.endif

.if !defined(WITHOUT_GEANY_SPELLCHECK)
BUILD_PLUGINS+=	,spellcheck
LIBDEPENS+=	enchant:${PORTSDIR}/textproc/enchant
PLUGINS+=	spellcheck.so
.endif

.if !defined(BUILD_PLUGINS)
IGNORE=	no plugins selected
.endif

.if !defined(WITHOUT_NLS)
PO_FILES=	be ca da de es fr gl ja pt pt_BR ru tr zh_CN
.for i in ${PO_FILES}
PLIST_FILES+=	share/locale/${i}/LC_MESSAGES/geany-plugins.mo
.endfor
.endif

.for i in ${PLUGINS}
PLIST_FILES+=	lib/geany/${i}
.endfor

do-configure:
	BUILD_PLUGINS=$(${ECHO} ${BUILD_PLUGINS} | ${SED} -e 's/^,//')
	@${WRKSRC}/waf configure --enable-plugins="${BUILD_PLUGINS}" -b ${WRKSRC}/_build_

do-install:
.for i in ${PLUGINS}
	@${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/${i} ${PREFIX}/lib/geany/
.endfor
.if !defined(WITHOUT_GEANY_GEANYGDB)
	@${MKDIR} ${PREFIX}/libexec/geany-plugins/geanygdb
	@${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/geanygdb.so ${PREFIX}/lib/geany/
	@${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/ttyhelper ${PREFIX}/libexec/geany-plugins/geanygdb/
.endif
.if !defined(WITHOUT_GEANY_GEANYLUA)
	@${MKDIR} ${PREFIX}/lib/geany-plugins/geanylua
	@${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/libgeanylua.so ${PREFIX}/lib/geany-plugins/geanylua/
	@${INSTALL_PROGRAM} ${WRKSRC}/_build_/default/geanylua.so ${PREFIX}/lib/geany/
	@(cd ${WRKSRC}/geanylua/examples/ && ${COPYTREE_SHARE} \* ${PREFIX}/share/geany-plugins/geanylua/ "! -name Makefile.in -and ! -name Makefile.am")
	@(cd ${WRKSRC}/geanylua/docs/ && ${COPYTREE_SHARE} \* ${PREFIX}/share/doc/geany-plugins/geanylua/ "! -name Makefile.in -and ! -name Makefile.am")
.endif
.if !defined(WITHOUT_NLS)
.for i in ${PO_FILES}
	@${INSTALL_DATA} ${WRKSRC}/_build_/default/po/${i}.mo ${PREFIX}/share/locale/${i}/LC_MESSAGES/geany-plugins.mo
.endfor
.endif

.include <bsd.port.post.mk>
