# New ports collection makefile for:	OpenOffice.org for Japanese language
# Date created:		Tue Jun 11 16:47:21 UTC 2002
# Whom:		Martin Blapp <mbr@FreeBSD.org> and Mario Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese

LANG_PKGNAME=	ja
LANG_EXT=	81
LANG_CONFIGURE_ARG=	JAPN
MASTERDIR=	${.CURDIR}/../../editors/openoffice-1.0
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/TrueType/kochi-mincho-subst.ttf:${PORTSDIR}/japanese/kochi-ttfonts

L10NHELP=       helpcontent_${LANG_EXT}_unix.tgz

NO_LATEST_LINK=	yes
.include "${MASTERDIR}/Makefile"
