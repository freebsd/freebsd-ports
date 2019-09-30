# $FreeBSD$

GEANY_VER=		1.36
GEANY_PLUGINS_GTK2=	geanypy \
			multiterm

GEANY_PLUGINS_GTK3=	markdown

GEANY_PLUGINS_ALL=	addons \
			autoclose \
			automark \
			codenav \
			commander \
			ctags \
			debugger \
			defineformat \
			doc \
			extrasel \
			gendoc \
			geniuspaste \
			git-changebar \
			insertnum \
			latex \
			lineoperations \
			lipsum \
			lua \
			macro \
			miniscript \
			numberedbookmarks \
			overview \
			pairtaghighlighter \
			pg \
			pohelper \
			pretty-printer \
			projectorganizer \
			prj \
			scope \
			sendmail \
			shiftcolumn \
			spellcheck \
			tableconvert \
			treebrowser \
			updatechecker \
			vc \
			vimode \
			workbench \
			xmlsnippets

addons_DESC=		various small addons
autoclose_DESC=		brackets autocompletion
automark_DESC=		highlights all words that match selected word
codenav_DESC=		some facilities for navigating in the code
commander_DESC=		command panel for rapid access to any action
ctags_DESC=		generate and query ctags files
debugger_DESC=		debugging support (via GDB currently)
defineformat_DESC=	on-the-fly \#define formatter
doc_DESC=		execute command on the word at cursor position
geanypy_DESC=		support for Python plugins
extrasel_DESC=		additional selection tools
gendoc_DESC=		generate documentation from the sources comments
geniuspaste_DESC=	pastebins support
git-changebar_DESC=	highlight changed files tracked with Git
insertnum_DESC=		replace selection with integer numbers
latex_DESC=		LaTeX support
lineoperations_DESC=	Simple line functions that can be applied to an open file
lipsum_DESC=		Lorem Ipsum generator
lua_DESC=		Lua scripting
macro_DESC=		user defined macros
markdown_DESC=		real-time preview of rendered Markdown
miniscript_DESC=	pipe text/documents via script (shell, perl, awk, etc.)
multiterm_DESC=		multi-tabbed virtual terminals emulator
numberedbookmarks_DESC=	additional numbered bookmarks
overview_DESC=		zoomed-out view of open files
pairtaghighlighter_DESC=	highlight matching opening/closing HTML tags
pg_DESC=		encrypt, decrypt and verify signatures with GnuPG
pohelper_DESC=		support for gettext translation files
pretty-printer_DESC=	formats XML and make it human-readable
projectorganizer_DESC=	extension of Geany's project management
prj_DESC=		alternative project manager
scope_DESC=		graphical GDB front-end
sendmail_DESC=		send a document as attachment
shiftcolumn_DESC=	move blocks of text horizontally
spellcheck_DESC=	spell check via Enchant
tableconvert_DESC=	convert tabulator separated selection into a table
treebrowser_DESC=	alternate file browser
updatechecker_DESC=	check for new version of Geany
utilslib_DESC=		utility library
vc_DESC=		access to different version-control systems
vimode_DESC=		vim-mode plugin for Geany written by a guy who does not use Vim
workbench_DESC=		manage multiple projects in geany
xmlsnippets_DESC=	XML/HTML tag autocompletion

doc_DIR=		geanydoc
ctags_DIR=		geanyctags
extrasel_DIR=		geanyextrasel
gendoc_DIR=		geanygendoc
insertnum_DIR=		geanyinsertnum
latex_DIR=		latex
lipsum_DIR=		lipsum
lua_DIR=		geanylua
macro_DIR=		geanymacro
miniscript_DIR=		geanyminiscript
numberedbookmarks_DIR=	geanynumberedbookmarks
pg_DIR=			geanypg
prj_DIR=		geanyprj
utilslib_DIR=		utils
vc_DIR=			geanyvc

git-changebar_SWITCH=	--enable-gitchangebar
pretty-printer_SWITCH=	--enable-pretty_printer

GEANY_UTIL=		debugger numberedbookmarks scope treebrowser workbench
