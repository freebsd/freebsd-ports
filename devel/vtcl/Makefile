# New ports collection makefile for:	vtcl
# Version required:	1.09
# Date Created:		29 May 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id$
#

DISTNAME=	vt-1.09
PKGNAME=	vtcl-1.09
CATEGORIES=	devel x11 tk42
MASTER_SITES=	http://www.neuron.com/stewart/vtcl/dload/ \
		ftp://ftp.neuron.com/pub/

MAINTAINER=	vanilla@MinJe.com.TW

BUILD_DEPENDS=	wish4.2:${PORTSDIR}/x11/tk42

WRKSRC=		${WRKDIR}/vtcl
NO_BUILD=	yes

do-install:
	@ ${MKDIR} ${PREFIX}/lib/vtcl/images
	@ ${MKDIR} ${PREFIX}/lib/vtcl/lib
	@ ${INSTALL_SCRIPT} ${WRKSRC}/vtcl ${PREFIX}/bin

.for data in ANNOUNCE CHANGES LICENSE README TODO vt.tcl
	@ ${INSTALL_DATA} ${WRKSRC}/${data} ${PREFIX}/lib/vtcl
.endfor

.for image in anchor.gif anchor_c.ppm anchor_e.ppm anchor_n.ppm anchor_ne.ppm anchor_nw.ppm anchor_s.ppm anchor_se.ppm anchor_sw.ppm anchor_w.ppm bg.gif border.gif curse.xbm down.xbm ellipses.gif fg.gif fontbase.gif fontsize.gif fontstyle.gif icon_button.gif icon_canvas.gif icon_checkbutton.gif icon_entry.gif icon_frame.gif icon_label.gif icon_listbox.gif icon_menu.gif icon_menubutton.gif icon_message.gif icon_radiobutton.gif icon_scale_h.gif icon_scale_v.gif icon_scrollbar_h.gif icon_scrollbar_v.gif icon_text.gif icon_tixComboBox.gif icon_tixLabelFrame.gif icon_tixNoteBook.gif icon_toplevel.gif justify.gif mgr_grid.gif mgr_pack.gif mgr_place.gif mini-vtcl.xpm ofg.gif rel_groove.gif rel_raised.gif rel_ridge.gif rel_sunken.gif relief.gif title.gif
	@ ${INSTALL_DATA} ${WRKSRC}/images/${image} ${PREFIX}/lib/vtcl/images
.endfor

.for lib in about.tcl attrbar.tcl attredit.tcl balloon.tcl bind.tcl color.tcl command.tcl compound.tcl compounds.tcl console.tcl do.tcl dragsize.tcl dump.tcl edit.tcl file.tcl filedlg.tcl globals.tcl handle.tcl help.tcl input.tcl lib_core.tcl lib_tix.tcl mgrs.tcl misc.tcl name.tcl prefs.tcl proc.tcl remove.sh replace.sh status.tcl tabpanel.tcl tclet.tcl tmp.tmp toolbar.tcl tops.tcl tree.tcl var.tcl vtclib.tcl widget.tcl
	@ ${INSTALL_DATA} ${WRKSRC}/lib/${lib} ${PREFIX}/lib/vtcl/lib
.endfor

.include <bsd.port.mk>
