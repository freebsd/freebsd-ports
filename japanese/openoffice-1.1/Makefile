# New ports collection makefile for: OpenOffice.org for Japanese language
# Date created:		Wed Apr 9 12:32:47 JST 2003
# Whom:		Maho Nakata <maho@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese

LANG_PKGNAME=	ja
LANG_EXT=	81
LANG_CONFIGURE_ARG=	JAPN
MASTERDIR=	${.CURDIR}/../../editors/openoffice-1.1
MASTER_SITES+=	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/openoffice/stable/&,}
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/TrueType/sazanami-mincho.ttf:${PORTSDIR}/japanese/sazanami-ttf
L10NHELP=	helpcontent_${LANG_EXT}_unix.tgz

.include "${MASTERDIR}/Makefile"
