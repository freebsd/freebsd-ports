# ex:ts=8
# Ports collection makefile for:  mutt w/pgp hooks
# Date created:			  Thur July 25, 1996
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

CATEGORIES=	chinese

MASTERDIR=	${.CURDIR}/../../mail/mutt-devel
REVISEDATE=	20030807

MAINTAINER=	clive@FreeBSD.org
COMMENT=	The Mongrel of Mail User Agents with Chinese support

PATCH_SITES=	http://bsdchat.com/~clive/dist/mutt15/ \
		ftp://freebsd.sinica.edu.tw/pub/clive/mutt15/
PATCHFILES=	${PKGNAMEPREFIX}mutt-${PORTVERSION}-${REVISEDATE}.diff.gz

BROKEN=		"Incorrect distinfo"

WITH_MUTT_LOCALES_FIX=	yes
MUTT_CONFIGURE_ARGS+=	--without-wc-funcs
WITH_MUTT_NCURSES=	yes
.if !defined(PACKAGE_BUILDING)
WITHOUT_MUTT_SGMLFORMAT=	yes
WITHOUT_MUTT_HTML=		yes
WITHOUT_MUTT_COMPRESSED_FOLDERS=yes
.endif

MD5_FILE=	${.CURDIR}/distinfo
PKGMESSAGE=	${.CURDIR}/pkg-message

.include "${MASTERDIR}/Makefile"
# To be a satellite port, I do not have many choices to place this line.
LIB_DEPENDS+=	hz.0:${PORTSDIR}/chinese/autoconvert
