# New ports collection makefile for:	OpenOffice.org for German language
# Date created:		Tue Jun 11 16:47:21 UTC 2002
# Whom:		Martin Blapp <mbr@FreeBSD.org> and Mario Ferreira <lioux@FreeBSD.org>
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
MASTERDIR=	${.CURDIR}/../../editors/openoffice-1.0

COMMENT=	Office-Suite mit Textverarbeitung, Tabellenkalkulation, Datenbank und Praesentationsprogramm

NO_LATEST_LINK=	yes
.include "${MASTERDIR}/Makefile"
