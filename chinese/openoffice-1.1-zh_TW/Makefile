# New ports collection makefile for:	OpenOffice for Traditional Chinese
# Date created:		Nov 9 08:30:32 JST 2003
# Whom:			chshen <statue@freebsd.sinica.edu.tw> and NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	chinese

LANG_PKGNAME=	zh
LANG_SUFFIX=	TW
LANG_EXT=	88
LANG_CONFIGURE_ARG=	CHINTRAD
BUILD_DEPENDS+=	${PREFIX}/share/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf
MASTERDIR=	${.CURDIR}/../../editors/openoffice-1.1
L10NHELP=       helpcontent_${LANG_EXT}_unix.tgz

.include "${MASTERDIR}/Makefile"
