# New ports collection makefile for:	ja-openoffice-templates
# Date created:				2003/10/10
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	templates
PORTVERSION=	1.1.0.20031010
PORTREVISION=	1
CATEGORIES=	japanese editors
MASTER_SITES=	http://desktop.good-day.net/ooo11/
PKGNAMEPREFIX=	ja-openoffice-
DISTNAME=	impress_templates
DIST_SUBDIR?=	openoffice1.1

MAINTAINER=	openoffice@FreeBSD.org
COMMENT=	OpenOffice.org 1.1.0 Impress Templates
PLIST=		${WRKDIR}/pkg-plist

RUN_DEPENDS=	${PREFIX}/${OPENOFFICE}/program/soffice:${PORTSDIR}/japanese/openoffice-1.1

OPENOFFICE=	OpenOffice.org1.1.0

OOTEMPLATES=	Black-cyan-yellow.ja.sti	\
		Black-orange.ja.sti		\
		Blue-yellow-white.ja.sti	\
		BlueBoxes_ja_11.sti		\
		BlueSilver_ja_11.sti		\
		BlueWavesTempl-1_ja_11.sti	\
		Blue_Circles_ja_11.sti		\
		Blue_Lines.sti			\
		Candy.ja.sti			\
		Cheesy.ja.sti			\
		Cubes_1x_ja_11.sti		\
		Foot-prints.ja.sti		\
		Grad-blue.ja.sti		\
		Grad-blue_2.ja.sti		\
		Grad-blue_3.ja.sti		\
		Grad-cyan-black.ja.sti		\
		Grad-gray-blue.ja.sti		\
		Grad-lightblue.ja.sti		\
		Grad-lightblue_2.ja.sti		\
		Grad-mediumblue.ja.sti		\
		Grad-purple.ja.sti		\
		Gray-green.ja.sti		\
		Hatch_ja_11.sti			\
		Marble.ja.sti			\
		MarbleTempl-2_ja_11.sti		\
		Music.ja.sti			\
		Notepad_ja_11.sti		\
		OOo.sti				\
		OOo2.sti			\
		Ortra_ja_11.sti			\
		Pixels.ja.sti			\
		Roses.ja.sti			\
		Solar_ja_11.sti			\
		Sunburst_ja_11.sti		\
		White-blue.ja.sti		\
		White-blue_sky.ja.sti		\
		White-red.ja.sti		\
		White-red_2.ja.sti		\
		White-red_3.ja.sti		\
		With-year-2003.ja.sti		\
		With-year-2004.ja.sti		\
		With-year-2005.ja.sti		\
		With-years.ja.sti		\
		blue.sti			\
		coolblack.sti			\
		landscape.sti			\
		sun4.sti

do-build:
.for FILE in ${OOTEMPLATES}
	@${ECHO_CMD} ${OPENOFFICE}/share/template/japanese/layout/${FILE} >> ${PLIST}
.endfor

do-install:
.for FILE in ${OOTEMPLATES}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${OPENOFFICE}/share/template/japanese/layout/${FILE}
.endfor

.include <bsd.port.mk>
