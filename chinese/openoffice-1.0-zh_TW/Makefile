# New ports collection makefile for:	OpenOffice.org for Traditional Chinese
# Date created:		Fri Jul 20 10:12:21 CET 2002
# Whom:			chshen <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

CATEGORIES=	chinese

NO_LATEST_LINK=	yes
LANG_PKGNAME=	zh
LANG_SUFFIX=	TW
LANG_EXT=	88
LANG_CONFIGURE_ARG=	CHINTRAD
BUILD_DEPENDS+=	${PREFIX}/share/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf
MASTERDIR=	${.CURDIR}/../../editors/openoffice-1.0

.include "${MASTERDIR}/Makefile"
