# New ports collection makefile for:	cream
# Date created:		2004-08-25
# Whom:			Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	cream
PORTVERSION=	0.30
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Gvim extension with many features

RUN_DEPENDS+=	${LOCALBASE}/bin/gvim:${PORTSDIR}/editors/vim

NO_BUILD=	YES

PLIST_FILES=	bin/cream

# needs updating for each major vim update.
VIMRUNTIMEDIR=	share/vim/vim63

CREAM_FILES=	EasyHtml.vim EnhancedCommentify.vim calendar.vim \
		cream-abbr-eng.vim cream-abbr-fre.vim cream-abbr.vim \
		cream-addon.vim cream-ascii.vim cream-autocmd.vim \
		cream-behavior.vim cream-bookmarks.vim \
		cream-capitalization.vim cream-colors-blackwhite.vim \
		cream-colors-chocolateliquor.vim cream-colors-dawn.vim \
		cream-colors-default.vim cream-colors-navajo-night.vim \
		cream-colors-navajo.vim cream-colors-night.vim \
		cream-colors-oceandeep.vim cream-colors-terminal.vim \
		cream-colors-zenburn.vim cream-colors.vim cream-columns.vim \
		cream-conf.example.vim cream-devel.vim cream-expertmode.vim \
		cream-explorer.vim cream-filetype-c.vim \
		cream-filetype-html.vim cream-filetype-txt.vim \
		cream-filetype-vim.vim cream-filetype.vim cream-find.vim \
		cream-gui.vim cream-justify.vim cream-keys.vim cream-lib.vim \
		cream-macros.vim cream-menu-developer.vim cream-menu-edit.vim \
		cream-menu-file.vim cream-menu-format.vim cream-menu-help.vim \
		cream-menu-insert.vim cream-menu-mru.vim cream-menu-popup.vim \
		cream-menu-settings.vim cream-menu-toolbar.vim \
		cream-menu-tools.vim cream-menu-window-buffer.vim \
		cream-menu-window.vim cream-menu.vim cream-numberlines.vim \
		cream-playpen.vim cream-pop.vim cream-print.vim \
		cream-replace.vim cream-replacemulti.vim cream-server.vim \
		cream-settings.vim cream-showinvisibles.vim cream-spell.vim \
		cream-statusline.vim cream-window-buffer.vim cream.vim creamrc \
		genutils.vim imaps.vim multvals.vim opsplorer.vim taglist.vim

CREAM_ADDONS=	cream-colorinvert.vim cream-convert-hex.vim \
		cream-cream-bugreport.vim cream-cream-ctags.vim \
		cream-cream-fileformat.vim cream-cream-foldfunctions.vim \
		cream-cream-keytest.vim cream-cream-release.vim \
		cream-cream-update.vim cream-cream-vim-abbrev.vim \
		cream-dailyread.vim cream-debinary.vim \
		cream-email-formatter.vim cream-email-munge.vim \
		cream-encrypt-algorithmic.vim cream-encrypt-h4x0r.vim \
		cream-encrypt-hexme.vim cream-encrypt-rot13.vim \
		cream-highlight-ctrlchars.vim cream-highlight-mbyte.vim \
		cream-ispell.vim cream-sort.vim cream-spell-french.vim \
		cream-str-invert.vim cream-text2html.vim cream-timestamp.vim

CREAM_BITMAPS=	book.xpm broken_image.xpm copy_alt.xpm cut_alt.xpm exit.xpm \
		font.xpm help.xpm new.xpm open.xpm paste.xpm print.xpm \
		redo.xpm save.xpm save_all.xpm save_as.xpm search.xpm \
		search_and_replace.xpm spellcheck.xpm text_align_center.xpm \
		text_align_justify.xpm text_align_left.xpm \
		text_align_right.xpm undo.xpm

CREAM_DOCS=	BUGS.txt CHANGELOG.txt COPYING.txt DEVELOPER.txt FILELIST.txt \
		KEYBOARD.txt PressRelease.txt README.txt RELEASE.txt \
		SPELLDICTS.txt SPELLTEST-ENG.txt TODO.txt WINDOWS.txt

CREAM_HTML=	background.html changelog.html contribute.html creamlogo.png \
		devel.html downloads.html faq.html favicon.png features.html \
		goals.html hate.html index.html installation.html \
		keyboardshortcuts.html license.html links.html love.html \
		maillist.html main.css otherfiles.html screenshot-arabic1.png \
		screenshot-popup.png screenshot1-thumb.png screenshot1.png \
		screenshot2-thumb.png screenshot2.png screenshot3-thumb.png \
		screenshot3.png screenshot4-thumb.png screenshot4.png \
		screenshot5-thumb.png screenshot5.png screenshot6-thumb.png \
		screenshot6.png screenshot7-thumb.png screenshot7.png \
		screenshot8-thumb.png screenshot8.png screenshots.html \
		screenshots1-closeup.html screenshots2-closeup.html \
		screenshots3-closeup.html screenshots4-closeup.html \
		screenshots5-closeup.html screenshots6-closeup.html \
		screenshots7-closeup.html screenshots8-closeup.html \
		spellcheck.html statusline-closeup.html statusline-thumb.png \
		statusline.png todo.html vim.html

CREAM_HELP=	EnhancedCommentify.txt opsplorer.txt

CREAM_SPELL=	cream-spell-dict-eng-s-br_1.vim \
		cream-spell-dict-eng-s-br_2.vim \
		cream-spell-dict-eng-s-br_3.vim \
		cream-spell-dict-eng-s-br_4.vim \
		cream-spell-dict-eng-s-ca_1.vim \
		cream-spell-dict-eng-s-ca_2.vim \
		cream-spell-dict-eng-s-ca_3.vim \
		cream-spell-dict-eng-s-ca_4.vim \
		cream-spell-dict-eng-s-us_1.vim \
		cream-spell-dict-eng-s-us_2.vim \
		cream-spell-dict-eng-s-us_3.vim \
		cream-spell-dict-eng-s-us_4.vim \
		cream-spell-dict-eng-s_1.vim \
		cream-spell-dict-eng-s_2.vim \
		cream-spell-dict-eng-s_3.vim \
		cream-spell-dict-eng-s_4.vim

do-install:
		#creating directories
		${MKDIR}	${PREFIX}/${VIMRUNTIMEDIR}/cream/
		${MKDIR}	${PREFIX}/${VIMRUNTIMEDIR}/cream/addons/
		${MKDIR}	${PREFIX}/${VIMRUNTIMEDIR}/cream/bitmaps/
		${MKDIR}	${PREFIX}/${VIMRUNTIMEDIR}/cream/docs/
		${MKDIR}	${PREFIX}/${VIMRUNTIMEDIR}/cream/docs-html/
		${MKDIR}	${PREFIX}/${VIMRUNTIMEDIR}/cream/help/
		${MKDIR}	${PREFIX}/${VIMRUNTIMEDIR}/cream/spelldicts/
		#installing files
.for f in ${CREAM_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${VIMRUNTIMEDIR}/cream
.endfor
.for f in ${CREAM_ADDONS}
	${INSTALL_DATA} ${WRKSRC}/addons/${f} \
		${PREFIX}/${VIMRUNTIMEDIR}/cream/addons/
.endfor
.for f in ${CREAM_BITMAPS}
	${INSTALL_DATA} ${WRKSRC}/bitmaps/${f} \
		${PREFIX}/${VIMRUNTIMEDIR}/cream/bitmaps/
.endfor
.for f in ${CREAM_DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} \
		${PREFIX}/${VIMRUNTIMEDIR}/cream/docs/
.endfor
.for f in ${CREAM_HTML}
	${INSTALL_DATA} ${WRKSRC}/docs-html/${f} \
		${PREFIX}/${VIMRUNTIMEDIR}/cream/docs-html/
.endfor
.for f in ${CREAM_HELP}
	${INSTALL_DATA} ${WRKSRC}/help/${f} \
		${PREFIX}/${VIMRUNTIMEDIR}/cream/help/
.endfor
.for f in ${CREAM_SPELL}
	${INSTALL_DATA} ${WRKSRC}/spelldicts/${f} \
		${PREFIX}/${VIMRUNTIMEDIR}/cream/spelldicts/
.endfor
	 ${INSTALL_SCRIPT} ${WRKSRC}/cream ${PREFIX}/bin/

post-install:
# create the package listings
.for f in ${CREAM_FILES}
	${ECHO} ${VIMRUNTIMEDIR}/cream/${f} >>${TMPPLIST}
.endfor
.for f in ${CREAM_ADDONS}
	${ECHO} ${VIMRUNTIMEDIR}/cream/addons/${f} >>${TMPPLIST}
.endfor
.for f in ${CREAM_BITMAPS}
	${ECHO} ${VIMRUNTIMEDIR}/cream/bitmaps/${f} >>${TMPPLIST}
.endfor
.for f in ${CREAM_DOCS}
	${ECHO} ${VIMRUNTIMEDIR}/cream/docs/${f} >>${TMPPLIST}
.endfor
.for f in ${CREAM_HTML}
	${ECHO} ${VIMRUNTIMEDIR}/cream/docs-html/${f} >>${TMPPLIST}
.endfor
.for f in ${CREAM_HELP}
	${ECHO} ${VIMRUNTIMEDIR}/cream/help/${f} >>${TMPPLIST}
.endfor
.for f in ${CREAM_SPELL}
	${ECHO} ${VIMRUNTIMEDIR}/cream/spelldicts/${f} >>${TMPPLIST}
.endfor
	${ECHO} "@dirrm ${VIMRUNTIMEDIR}/cream/addons" >>${TMPPLIST}
	${ECHO} "@dirrm ${VIMRUNTIMEDIR}/cream/bitmaps" >>${TMPPLIST}
	${ECHO} "@dirrm ${VIMRUNTIMEDIR}/cream/docs" >>${TMPPLIST}
	${ECHO} "@dirrm ${VIMRUNTIMEDIR}/cream/docs-html" >>${TMPPLIST}
	${ECHO} "@dirrm ${VIMRUNTIMEDIR}/cream/help" >>${TMPPLIST}
	${ECHO} "@dirrm ${VIMRUNTIMEDIR}/cream/spelldicts" >>${TMPPLIST}
	${ECHO} "@dirrm ${VIMRUNTIMEDIR}/cream" >>${TMPPLIST}

.include <bsd.port.mk>
