# New ports collection makefile for:    OpenOffice for Simplified Chinese
# Date created:         Tue Jun 11 16:47:21 UTC 2002
# Whom:         Martin Blapp <mbr@FreeBSD.org> and Mario Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=     chinese editors

LANG_PKGNAME=   zh
LANG_SUFFIX=	CN
LANG_EXT=       86
LANG_CONFIGURE_ARG=     CHINSIM
BUILD_DEPENDS+=	${PREFIX}/share/fonts/TrueType/gbsn00lp.ttf:${PORTSDIR}/chinese/arphicttf
MASTERDIR=      ${.CURDIR}/../../editors/openoffice

.include "${MASTERDIR}/Makefile"
