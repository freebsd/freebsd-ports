# New ports collection makefile for: tvi
# Version required:	0.9.0
# Date created:		3 Jan 1999
# Whom:			SUGIMURA Takashi <sugimura@jp.FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	tvi-0.9.0
PKGNAME=	ja-tvi-0.9.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.kt.rim.or.jp/~motomu/tvi/Arc/

MAINTAINER=	sugimura@jp.FreeBSD.ORG

RUN_DEPENDS=	wish4.2jp:${PORTSDIR}/japanese/tk42

NO_BUILD=	yes

TVILIBDIR=	${PREFIX}/lib/${DISTNAME}
TVILIBSCRIPTS=	tvi makeicon3
TVILIBFILES=	COPYING ChangeLog README Tvi_help_acknowledge.html \
	Tvi_help_contact.html Tvi_help_develop.html Tvi_help_index.html \
	Tvi_help_install.html Tvi_help_intro.html Tvi_help_license.html \
	Tvi_help_manual.html Tvi_help_required.html img_bookmark img_coloff \
	img_colon img_compile img_ghost img_help img_open img_print img_save \
	img_spell img_terminal img_xdvi latex_commands latex_environments \
	latex_misc latex_symbols latex_tcl load_baloons main_bind main_ini \
	main_ini_value main_rc main_tcl main_tk menu_bugfixed.tcl \
	number sed_commands tvi_dialog tvi_fbox tvi_text

do-install:
	${MKDIR} ${TVILIBDIR}
.for i in ${TVILIBSCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/$i ${PREFIX}/bin/$i
.endfor
.for i in ${TVILIBFILES}
	${INSTALL_DATA} ${WRKSRC}/$i ${TVILIBDIR}/$i
.endfor

.include <bsd.port.mk>
