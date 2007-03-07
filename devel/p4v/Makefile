# New ports collection makefile for:	p4v
# Date created:				14 February 2004
# Whom:					bms@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	p4v
PORTVERSION=	2007.1.116736
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/perforce/r07.1/bin.freebsd54x86/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Visual client for Perforce SCM

NO_CDROM=	Binary redistribution restrictions in effect
RESTRICTED=	${NO_CDROM}

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST=		${MASTERDIR}/pkg-plist.${MACHINE_ARCH}
MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}

P4V_ICONS_DIR=	P4VResources/icons
P4V_ICONS=	p4v_16_low.png p4v_32_high.png p4v_32_low.png p4v_48_high.png

P4V_DOCS_DIR=	P4VResources/p4vhelp
P4V_DOCS=	About_Perforce_products.html \
		About_file_icons.html \
		Adding_files_to_the_depot.html \
		Changing_a_file_s_type.html \
		Configuring_display_preferences.html \
		Connecting_to_the_Perforce_server.html \
		Defining_a_client_view.html \
		Deleting_files.html \
		Displaying_a_file_s_revision_history.html \
		Displaying_client_specifications.html \
		Editing_files.html \
		Getting_more_information.html \
		Getting_started_with_Perforce.html \
		Integrating_files_into_codelines.html \
		Managing_branch_specifications.html \
		Managing_jobs.html \
		Managing_labels.html \
		Managing_users.html \
		P4V_shortcuts.html \
		Renaming_files.html \
		Resolving_files.html \
		Retrieving_files_from_the_depot.html \
		The_P4V_windows.html \
		Working_with_changelists.html \
		ancillary_p4v_files.html \
		custom_tools.html \
		diffing_folders.html \
		p4v-gs.pdf \
		p4vindex.html \
		revision_graph.html \
		time_lapse.html

P4V_IMGS_DIR=	P4VResources/p4vhelp/p4images
P4V_IMGS=	p4v_bookmark.png p4v_file_add.png p4v_file_add_other.png \
		p4v_file_delete.png p4v_file_delete_notsync.png \
		p4v_file_delete_other.png p4v_file_delete_resolve.png \
		p4v_file_deleted.png p4v_file_edit_head.png \
		p4v_file_edit_notsync.png p4v_file_edit_other.png \
		p4v_file_edit_other_notsyn.png p4v_file_edit_other_notsync.png \
		p4v_file_edit_resolve.png \
		p4v_file_edit_resolve_other_delete.png \
		p4v_file_lock.png p4v_file_lock_other.png \
		p4v_file_needs_resolve.png p4v_file_notmapped.png \
		p4v_file_notsync.png p4v_file_rev_add.png \
		p4v_file_rev_branch.png p4v_file_rev_delete.png \
		p4v_file_rev_edit.png p4v_file_rev_have_add.png \
		p4v_file_rev_have_branch.png p4v_file_rev_have_edit.png \
		p4v_file_revision_integrated.png p4v_file_revsynced.png \
		p4v_file_sync.png p4v_file_txt.png p4v_file_ws.png \
		p4v_filter.png p4v_filters.png p4v_folder_diff_screenshot.png \
		p4v_pin.png p4v_revision_graph_screenshot.png p4v_sort.png \
		p4v_tearoff.png p4v_time_lapse_screenshot.png p4v_views.png

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		please upgrade to FreeBSD 5.x or newer
.endif
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c_r.5:${PORTSDIR}/misc/compat5x
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p4v ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/${P4V_ICONS_DIR}
.for _ICONFILE in ${P4V_ICONS}
	${INSTALL_DATA} ${WRKSRC}/${P4V_ICONS_DIR}/${_ICONFILE} ${PREFIX}/share/${P4V_ICONS_DIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/${P4V_DOCS_DIR} ${PREFIX}/share/${P4V_IMGS_DIR}
.for _DOCFILE in ${P4V_DOCS}
	${INSTALL_MAN} ${WRKSRC}/${P4V_DOCS_DIR}/${_DOCFILE} ${PREFIX}/share/${P4V_DOCS_DIR}
.endfor
.for _IMGFILE in ${P4V_IMGS}
	${INSTALL_MAN} ${WRKSRC}/${P4V_IMGS_DIR}/${_IMGFILE} ${PREFIX}/share/${P4V_IMGS_DIR}
.endfor
.endif

post-install:
	${SED} -e 's!%%PREFIX%%!${PREFIX}!' ${PKGMESSAGE}

.include <bsd.port.post.mk>
