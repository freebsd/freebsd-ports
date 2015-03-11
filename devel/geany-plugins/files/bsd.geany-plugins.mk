# $FreeBSD$

GEANY_VER=	1.24
GEANY_PLUGINS_ALL=	addons \
			autoclose \
			codenav \
			commander \
			debugger \
			defineformat \
			devhelp \
			doc \
			extrasel \
			geanypy \
			gendoc \
			geniuspaste \
			gproject \
			insertnum \
			latex \
			lipsum \
			lua \
			macro \
			miniscript \
			multiterm \
			numberedbookmarks \
			pairtaghighlighter \
			pg \
			pohelper \
			pretty-printer \
			prj \
			scope \
			sendmail \
			shiftcolumn \
			spellcheck \
			tableconvert \
			treebrowser \
			updatechecker \
			vc \
			webhelper \
			xmlsnippets

# markdown plugin is excluded, requires peg-markdown

addons_DESC=		various small addons
autoclose_DESC=		brackets autocompletion
codenav_DESC=		some facilities for navigating in the code
commander_DESC=		command panel for rapid access to any action
debugger_DESC=		debugging support (via GDB currently)
defineformat_DESC=	on-the-fly \#define formatter
devhelp_DESC=		API documentation browser
doc_DESC=		execute command on the word at cursor position
geanypy_DESC=		support for Python plugins
extrasel_DESC=		additional selection tools
gendoc_DESC=		generate documentation from the sources comments
geniuspaste_DESC=	pastebins support
gproject_DESC=		extension of Geany's project management
insertnum_DESC=		replaces selection with integer numbers
latex_DESC=		LaTeX support
lipsum_DESC=		Lorem Ipsum generator
lua_DESC=		Lua scripting
macro_DESC=		user defined macros
# markdown_DESC=		real-time preview of rendered Markdown
miniscript_DESC=	pipe text/documents via script (shell, perl, awk, etc.)
multiterm_DESC=		multi-tabbed virtual terminals emulator
numberedbookmarks_DESC=	additional numbered bookmarks
pairtaghighlighter_DESC=	highlights matching opening/closing HTML tags
pg_DESC=		encrypt, decrypt and verify signatures with GnuPG
pohelper_DESC=		support for gettext translation files
pretty-printer_DESC=	formats XML and make it human-readable
prj_DESC=		alternative project manager
scope_DESC=		graphical GDB front-end
sendmail_DESC=		send a document as attachment
shiftcolumn_DESC=	move blocks of text horizontally
spellcheck_DESC=	spell check via Enchant
tableconvert_DESC=	convert tabulator separated selection into a table
treebrowser_DESC=	alternate file browser
updatechecker_DESC=	check for new version of Geany
vc_DESC=		access to different version-control systems
webhelper_DESC=		web development facilities
xmlsnippets_DESC=	XML/HTML tag autocompletion

doc_DIR=		geanydoc
extrasel_DIR=		geanyextrasel
gendoc_DIR=		geanygendoc
insertnum_DIR=		geanyinsertnum
latex_DIR=		geanylatex
lipsum_DIR=		geanylipsum
lua_DIR=		geanylua
macro_DIR=		geanymacro
miniscript_DIR=		geanyminiscript
numberedbookmarks_DIR=	geanynumberedbookmarks
pg_DIR=			geanypg
prj_DIR=		geanyprj
sendmail_DIR=		geanysendmail
vc_DIR=			geanyvc

pretty-printer_SWITCH=	--enable-pretty_printer
