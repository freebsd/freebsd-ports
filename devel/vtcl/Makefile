# New ports collection makefile for:	vtcl
# Version required:	1.20
# Date Created:		29 May 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.12 1998/10/20 03:35:03 asami Exp $
#

DISTNAME=	current
PKGNAME=	vtcl-1.20
CATEGORIES=	devel tk80
MASTER_SITES=	http://www.neuron.com/stewart/vtcl/dload/ \
		ftp://ftp.neuron.com/pub/

MAINTAINER=	vanilla@FreeBSD.ORG

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/vtcl-1.2.0
NO_BUILD=	yes
DIST_SUBDIR=	vtcl

do-install:
	@ ${MKDIR} ${PREFIX}/lib/vtcl/images
	@ ${MKDIR} ${PREFIX}/lib/vtcl/images/edit
	@ ${MKDIR} ${PREFIX}/lib/vtcl/lib
	@ ${MKDIR} ${PREFIX}/share/doc/vtcl
	@ ${INSTALL_SCRIPT} ${WRKSRC}/vtcl ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/doc/tutorial.txt ${PREFIX}/share/doc/vtcl

.for data in Announce ChangeLog LICENSE README vt.tcl
	@ ${INSTALL_DATA} ${WRKSRC}/${data} ${PREFIX}/lib/vtcl
.endfor

.for image in anchor.gif anchor_c.ppm anchor_e.ppm anchor_n.ppm anchor_ne.ppm anchor_nw.ppm anchor_s.ppm anchor_se.ppm anchor_sw.ppm anchor_w.ppm bg.gif border.gif curse.xbm down.xbm ellipses.gif fg.gif fontbase.gif fontsize.gif fontstyle.gif icon_button.gif icon_canvas.gif icon_checkbutton.gif icon_entry.gif icon_frame.gif icon_graph.gif icon_hierbox.gif icon_label.gif icon_listbox.gif icon_menu.gif icon_menubutton.gif icon_message.gif icon_radiobutton.gif icon_scale_h.gif icon_scale_v.gif icon_scrollbar_h.gif icon_scrollbar_v.gif icon_stripchart.gif icon_text.gif icon_tixComboBox.gif icon_tixFileEntry.gif icon_tixLabelEntry.gif icon_tixLabelFrame.gif icon_tixMeter.gif icon_tixNoteBook.gif icon_tixOptionMenu.gif icon_tixPanedWindow.gif icon_tixScrolledHList.gif icon_tixScrolledListBox.gif icon_tixSelect.gif icon_tixTree.gif icon_tix_unknown.gif icon_toplevel.gif justify.gif mgr_grid.gif mgr_pack.gif mgr_place.gif mini-vtcl.xpm ofg.gif rel_groove.gif rel_raised.gif rel_ridge.gif rel_sunken.gif relief.gif title.gif unknown.gif
	@ ${INSTALL_DATA} ${WRKSRC}/images/${image} ${PREFIX}/lib/vtcl/images
.endfor

.for eimage in copy.gif cut.gif icons.gif new.gif open.gif paste.gif save.gif search.gif srchbak.gif srchfwd.gif
	@ ${INSTALL_DATA} ${WRKSRC}/images/edit/${eimage} ${PREFIX}/lib/vtcl/images/edit
.endfor

.for lib in about.tcl attrbar.tcl balloon.tcl bind.tcl color.tcl command.tcl compound.tcl compounds.tcl console.tcl do.tcl dragsize.tcl dump.tcl edit.tcl editor.tcl file.tcl globals.tcl handle.tcl help.tcl input.tcl lib_blt.tcl lib_core.tcl lib_itcl.tcl lib_tix.tcl menu.tcl misc.tcl name.tcl prefs.tcl proc.tcl propmgr.tcl remove.sh tabpanel.tcl tclet.tcl toolbar.tcl tops.tcl tree.tcl var.tcl vtclib.tcl widget.tcl
	@ ${INSTALL_DATA} ${WRKSRC}/lib/${lib} ${PREFIX}/lib/vtcl/lib
.endfor

.include <bsd.port.mk>
