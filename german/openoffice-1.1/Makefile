# New ports collection makefile for:	OpenOffice.org for German language
# Date created:		Nov 07 08:00:00 JST 2003
# Whom:		Martin Blapp <mbr@FreeBSD.org>, Mario Ferreira <lioux@FreeBSD.org> and NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	german

.if !defined (LANG) && !defined(USE_LANG)
USE_LANG=	de_DE.ISO8859-15
.endif
LANG_LIST=	de_DE.ISO8859-15 de_AT.ISO8859-15 de_DE.ISO8859-15 \
		de_DE.ISO8859-1 de_AT.ISO8859-1 de_DE.ISO8859-1
LANG_PKGNAME=	de
LANG_EXT=	49
L10NHELP=	helpcontent_${LANG_EXT}_unix.tgz
LANG_CONFIGURE_ARG=	GER
#
# Special case. We do not need LANG_CONFIGURE_ARG cause
# the EN_US and DE_DE versions are always built.
#
MASTERDIR=	${.CURDIR}/../../editors/openoffice-1.1

COMMENT=	Office-Suite mit Textverarbeitung, Tabellenkalkulation, Datenbank und Praesentationsprogramm

.include "${MASTERDIR}/Makefile"
