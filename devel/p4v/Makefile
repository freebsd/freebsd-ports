# New ports collection makefile for:	p4v
# Date created:				14 February 2004
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	p4v
PORTVERSION=	2008.2.200026
CATEGORIES=	devel
MASTER_SITES=	\
	http://filehost.perforce.com/perforce/r08.2/bin.freebsd60x86${MACHINE_ARCH:Mamd64:S/^amd/_/}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	perforce/${PORTNAME}-${PORTVERSION}/${ARCH}

MAINTAINER=	scf@FreeBSD.org
COMMENT=	Visual client for Perforce SCM

LIB_DEPENDS=	pthread.2:${PORTSDIR}/misc/compat6x

NO_CDROM=	Binary redistribution restrictions in effect
RESTRICTED=	${NO_CDROM}

ONLY_FOR_ARCHS=	amd64 i386
NO_BUILD=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}

.include <bsd.port.pre.mk>

P4V_BIN=	\
	bin/assistant_adp bin/p4merge bin/p4merge.bin bin/p4v bin/p4v.bin

P4V_LIBS=	\
	lib/p4v/qt4/lib/libQtAssistantClient.so.4 \
	lib/p4v/qt4/lib/libQtCore.so.4 \
	lib/p4v/qt4/lib/libQtGui.so.4 \
	lib/p4v/qt4/lib/libQtNetwork.so.4 \
	lib/p4v/qt4/lib/libQtXml.so.4 \
	lib/p4v/qt4/plugins/accessible/libqtaccessiblewidgets.so \
	lib/p4v/qt4/plugins/codecs/libqcncodecs.so \
	lib/p4v/qt4/plugins/codecs/libqjpcodecs.so \
	lib/p4v/qt4/plugins/codecs/libqkrcodecs.so \
	lib/p4v/qt4/plugins/codecs/libqtwcodecs.so \
	lib/p4v/qt4/plugins/imageformats/libqgif.so \
	lib/p4v/qt4/plugins/imageformats/libqico.so \
	lib/p4v/qt4/plugins/imageformats/libqjpeg.so \
	lib/p4v/qt4/plugins/imageformats/libqmng.so \
	lib/p4v/qt4/plugins/imageformats/libqsvg.so \
	lib/p4v/qt4/plugins/imageformats/libqtiff.so \
	lib/p4v/qt4/plugins/inputmethods/libqimsw-multi.so

P4V_ICONS=	\
	lib/p4v/P4VResources/icons/p4v_16_low.png \
	lib/p4v/P4VResources/icons/p4v_32_high.png \
	lib/p4v/P4VResources/icons/p4v_32_low.png \
	lib/p4v/P4VResources/icons/p4v_48_high.png

P4V_DIRS=	\
	lib/p4v/qt4/plugins/inputmethods \
	lib/p4v/qt4/plugins/imageformats \
	lib/p4v/qt4/plugins/codecs \
	lib/p4v/qt4/plugins/accessible \
	lib/p4v/qt4/plugins \
	lib/p4v/qt4/lib \
	lib/p4v/qt4 \
	lib/p4v/P4VResources/p4vhelp/p4images \
	lib/p4v/P4VResources/p4vhelp \
	lib/p4v/P4VResources/p4mergehelp/p4images \
	lib/p4v/P4VResources/p4mergehelp \
	lib/p4v/P4VResources/icons \
	lib/p4v/P4VResources \
	lib/p4v

P4V_DOCS=	\
	lib/p4v/P4VResources/p4mergehelp/assistant-manual.html \
	lib/p4v/P4VResources/p4mergehelp/diffing_files.html \
	lib/p4v/P4VResources/p4mergehelp/diffing_images.html \
	lib/p4v/P4VResources/p4mergehelp/merging_files.html \
	lib/p4v/P4VResources/p4mergehelp/p4mergehelp.adp \
	lib/p4v/P4VResources/p4vhelp/About_Perforce_products.html \
	lib/p4v/P4VResources/p4vhelp/About_file_icons.html \
	lib/p4v/P4VResources/p4vhelp/Adding_files_to_the_depot.html \
	lib/p4v/P4VResources/p4vhelp/Admin_homepage.html \
	lib/p4v/P4VResources/p4vhelp/Admin_managing_permissions.html \
	lib/p4v/P4VResources/p4vhelp/Admin_managing_users_and_groups.html \
	lib/p4v/P4VResources/p4vhelp/Changing_a_file_s_type.html \
	lib/p4v/P4VResources/p4vhelp/Configuring_display_preferences.html \
	lib/p4v/P4VResources/p4vhelp/Configuring_unicode.html \
	lib/p4v/P4VResources/p4vhelp/Connecting_to_the_Perforce_server.html \
	lib/p4v/P4VResources/p4vhelp/Defining_a_client_view.html \
	lib/p4v/P4VResources/p4vhelp/Deleting_files.html \
	lib/p4v/P4VResources/p4vhelp/Displaying_a_file_s_revision_history.html \
	lib/p4v/P4VResources/p4vhelp/Displaying_client_specifications.html \
	lib/p4v/P4VResources/p4vhelp/Editing_files.html \
	lib/p4v/P4VResources/p4vhelp/Getting_more_information.html \
	lib/p4v/P4VResources/p4vhelp/Getting_started_with_Perforce.html \
	lib/p4v/P4VResources/p4vhelp/Integrating_files_into_codelines.html \
	lib/p4v/P4VResources/p4vhelp/Managing_bookmarks.html \
	lib/p4v/P4VResources/p4vhelp/Managing_branch_specifications.html \
	lib/p4v/P4VResources/p4vhelp/Managing_jobs.html \
	lib/p4v/P4VResources/p4vhelp/Managing_labels.html \
	lib/p4v/P4VResources/p4vhelp/Offline.html \
	lib/p4v/P4VResources/p4vhelp/P4V_shortcuts.html \
	lib/p4v/P4VResources/p4vhelp/Renaming_files.html \
	lib/p4v/P4VResources/p4vhelp/Resolving_files.html \
	lib/p4v/P4VResources/p4vhelp/Retrieving_files_from_the_depot.html \
	lib/p4v/P4VResources/p4vhelp/The_P4V_windows.html \
	lib/p4v/P4VResources/p4vhelp/Utilities.html \
	lib/p4v/P4VResources/p4vhelp/Working_with_changelists.html \
	lib/p4v/P4VResources/p4vhelp/ancillary_p4v_files.html \
	lib/p4v/P4VResources/p4vhelp/assistant-manual.html \
	lib/p4v/P4VResources/p4vhelp/custom_tools.html \
	lib/p4v/P4VResources/p4vhelp/diffing_files.html \
	lib/p4v/P4VResources/p4vhelp/diffing_folders.html \
	lib/p4v/P4VResources/p4vhelp/diffing_images.html \
	lib/p4v/P4VResources/p4vhelp/folder_diff_cheatsheet.html \
	lib/p4v/P4VResources/p4vhelp/merging_files.html \
	lib/p4v/P4VResources/p4vhelp/p4v-gs.pdf \
	lib/p4v/P4VResources/p4vhelp/p4vhelp.adp \
	lib/p4v/P4VResources/p4vhelp/revision_graph.html \
	lib/p4v/P4VResources/p4vhelp/time_lapse.html

P4V_IMGS=	\
	lib/p4v/P4VResources/p4mergehelp/p4diff_help.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/addyourstheirs.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/basefile.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/choosechunk.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/deletedyourstheirs.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/editedtext.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/expandme.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/file1.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/file2.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/filediagram.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/find.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/gotoline.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/inline-button.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/inline-off.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/inline-on.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/lineend.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/linenumbers.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/nextdiff.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/p4_merge_help.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/sameyourstheirs.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/theiradd.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/theirdelete.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/youradd.png \
	lib/p4v/P4VResources/p4mergehelp/p4images/yourdelete.png \
	lib/p4v/P4VResources/p4mergehelp/p4merge_help.png \
	lib/p4v/P4VResources/p4vhelp/p4images/P4V_help_128x128.png \
	lib/p4v/P4VResources/p4vhelp/p4images/addyourstheirs.png \
	lib/p4v/P4VResources/p4vhelp/p4images/basefile.png \
	lib/p4v/P4VResources/p4vhelp/p4images/choosechunk.png \
	lib/p4v/P4VResources/p4vhelp/p4images/deletedyourstheirs.png \
	lib/p4v/P4VResources/p4vhelp/p4images/editedtext.png \
	lib/p4v/P4VResources/p4vhelp/p4images/expandme.png \
	lib/p4v/P4VResources/p4vhelp/p4images/file1.png \
	lib/p4v/P4VResources/p4vhelp/p4images/file2.png \
	lib/p4v/P4VResources/p4vhelp/p4images/filediagram.png \
	lib/p4v/P4VResources/p4vhelp/p4images/find.png \
	lib/p4v/P4VResources/p4vhelp/p4images/gotoline.png \
	lib/p4v/P4VResources/p4vhelp/p4images/inline-button.png \
	lib/p4v/P4VResources/p4vhelp/p4images/inline-off.png \
	lib/p4v/P4VResources/p4vhelp/p4images/inline-on.png \
	lib/p4v/P4VResources/p4vhelp/p4images/lineend.png \
	lib/p4v/P4VResources/p4vhelp/p4images/linenumbers.png \
	lib/p4v/P4VResources/p4vhelp/p4images/new_user.png \
	lib/p4v/P4VResources/p4vhelp/p4images/new_workspace.png \
	lib/p4v/P4VResources/p4vhelp/p4images/nextdiff.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4_merge_help.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4diff_help.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4merge_help.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v-search.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_16_high.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_admin_table_icon.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_bookmark.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_commandkey.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_connection_dialog.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_diffhighlight-ivory.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_diffhighlight-orange.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_diffhighlight-violet.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_add.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_add_other.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_add_other_ws.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_branch.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_delete.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_delete_notsync.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_delete_other.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_delete_resolve.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_deleted.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_differs.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_edit_head.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_edit_notsync.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_edit_other.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_edit_other_notsyn.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_edit_other_notsync.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_edit_resolve.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_edit_resolve_other_delete.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_lock.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_lock_other.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_needs_resolve.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_notmapped.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_notsync.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_rev_add.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_rev_branch.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_rev_delete.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_rev_edit.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_rev_have_add.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_rev_have_branch.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_rev_have_edit.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_revision_integrated.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_revsynced.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_sync.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_txt.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_file_ws.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_filter.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_filter_button.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_filter_content.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_filter_identical.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_filter_list.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_filter_unique.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_filters.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_folder_black_triangle.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_folder_diff_screenshot.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_folderdiff.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_help_16x16.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_integrate.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_integration_dialog.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_main_window.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_nextdiff.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_offline.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_offline_deleted.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_pin.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_revgraph_bracket.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_revgraph_branch.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_revgraph_diff.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_revgraph_highlighter.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_revgraph_options.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_revision_graph_screenshot.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_sort.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_tearoff.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_unmapped.png \
	lib/p4v/P4VResources/p4vhelp/p4images/p4v_views.png \
	lib/p4v/P4VResources/p4vhelp/p4images/sameyourstheirs.png \
	lib/p4v/P4VResources/p4vhelp/p4images/theiradd.png \
	lib/p4v/P4VResources/p4vhelp/p4images/theirdelete.png \
	lib/p4v/P4VResources/p4vhelp/p4images/tlv-find.png \
	lib/p4v/P4VResources/p4vhelp/p4images/tlv-goto.png \
	lib/p4v/P4VResources/p4vhelp/p4images/tlv-integhist.png \
	lib/p4v/P4VResources/p4vhelp/p4images/tlv-lifetimes.png \
	lib/p4v/P4VResources/p4vhelp/p4images/tlv-lineend.png \
	lib/p4v/P4VResources/p4vhelp/p4images/tlv-nextdiff.png \
	lib/p4v/P4VResources/p4vhelp/p4images/tlv-slider-increment.png \
	lib/p4v/P4VResources/p4vhelp/p4images/tlv-slider-multiple.png \
	lib/p4v/P4VResources/p4vhelp/p4images/tlv-slider-single.png \
	lib/p4v/P4VResources/p4vhelp/p4images/tlv-user.png \
	lib/p4v/P4VResources/p4vhelp/p4images/tlv_aging.png \
	lib/p4v/P4VResources/p4vhelp/p4images/tlv_linenumbers.png \
	lib/p4v/P4VResources/p4vhelp/p4images/youradd.png \
	lib/p4v/P4VResources/p4vhelp/p4images/yourdelete.png

PLIST_DIRS+=	${P4V_DIRS}
PLIST_FILES+=	${P4V_BIN} ${P4V_ICONS} ${P4V_LIBS}
.if !defined(NOPORTDOCS)
PLIST_FILES+=	${P4V_DOCS} ${P4V_IMGS}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/assistant_adp ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/p4merge.bin ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/p4v.bin ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/p4merge ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/p4v ${PREFIX}/bin
.for _DIR in ${P4V_DIRS}
	${MKDIR} ${PREFIX}/${_DIR}
.endfor
.for _ICONFILE in ${P4V_ICONS}
	${INSTALL_DATA} ${WRKSRC}/${_ICONFILE} ${PREFIX}/${_ICONFILE}
.endfor
.for _LIBFILE in ${P4V_LIBS}
	${INSTALL_PROGRAM} ${WRKSRC}/${_LIBFILE} ${PREFIX}/${_LIBFILE}
.endfor
.if !defined(NOPORTDOCS)
.for _DOCFILE in ${P4V_DOCS}
	${INSTALL_MAN} ${WRKSRC}/${_DOCFILE} ${PREFIX}/${_DOCFILE}
.endfor
.for _IMGFILE in ${P4V_IMGS}
	${INSTALL_MAN} ${WRKSRC}/${_IMGFILE} ${PREFIX}/${_IMGFILE}
.endfor
.endif

post-install:
	${SED} -e 's!%%PREFIX%%!${PREFIX}!' ${PKGMESSAGE}

.include <bsd.port.post.mk>
