# New ports collection makefile for:	OpenOffice for Japanese language
# Date created:		Tue Jun 11 16:47:21 UTC 2002
# Whom:		Martin Blapp <mbr@FreeBSD.org> and Mario Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese editors

LANG_PKGNAME=	ja
LANG_EXT=	81
LANG_CONFIGURE_ARG=	JAPN
MASTERDIR=	${.CURDIR}/../../editors/openoffice
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/TrueType/kochi-mincho.ttf:${PORTSDIR}/japanese/kochi-ttfonts
MASTER_SITES+=	ftp://ftp.kddlabs.co.jp/office/openoffice/ \
		ftp://ftp.sfc.wide.ad.jp/pub/OpenOffice/:help
L10NHELP=	helpcontent
.include "${MASTERDIR}/Makefile"
