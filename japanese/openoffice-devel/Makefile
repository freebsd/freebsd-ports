# New ports collection makefile for: OpenOffice(developer version) for Japanese language
# Date created:		Wed Apr 9 12:32:47 JST 2003
# Whom:		Maho Nakata <maho@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese

LANG_PKGNAME=	ja
LANG_EXT=	81
LANG_CONFIGURE_ARG=	JAPN
MASTERDIR=	${.CURDIR}/../../editors/openoffice-devel
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/TrueType/kochi-mincho-subst.ttf:${PORTSDIR}/japanese/kochi-ttfonts
L10NHELP=	helpcontent_${LANG_EXT}_unix.tgz

.include "${MASTERDIR}/Makefile"
