# New ports collection makefile for:    OpenOffice.org for Simplified Chinese
# Date created:         Tue Nov 11 08:00:00 JST 2003
# Whom:         Martin Blapp <mbr@FreeBSD.org>, Mario Ferreira <lioux@FreeBSD.org> and NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=     chinese

LANG_PKGNAME=   zh
LANG_SUFFIX=	CN
LANG_EXT=       86
LANG_CONFIGURE_ARG=     CHINSIM
BUILD_DEPENDS+=	${PREFIX}/share/fonts/TrueType/gbsn00lp.ttf:${PORTSDIR}/chinese/arphicttf
MASTERDIR=      ${.CURDIR}/../../editors/openoffice-1.1
L10NHELP=       helpcontent_${LANG_EXT}_unix.tgz

.include "${MASTERDIR}/Makefile"
