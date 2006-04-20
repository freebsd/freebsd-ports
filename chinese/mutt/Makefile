# ex:ts=8
# Ports collection makefile for:  mutt w/pgp hooks
# Date created:			  Thur July 25, 1996
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

CATEGORIES=	chinese

MASTERDIR=	${.CURDIR}/../../mail/mutt-devel
REVISEDATE=	20040617
PORTREVISION=	${REVISEDATE}

# XXX: Currently PORTREVISION assignment is not perfect. It needs to
# inherit its master port's PORTREVISION and be appended.

MAINTAINER=	clive@FreeBSD.org
COMMENT=	The Mongrel of Mail User Agents with Chinese support

PATCH_SITES=	http://wood.ite.ntnu.edu.tw/~clive/dist/mutt15/ \
		ftp://freebsd.sinica.edu.tw/pub/clive/mutt15/ \
		http://bsdchat.com/dist/mutt15/
PATCHFILES=	${PKGNAMEPREFIX}mutt-${PORTVERSION}-${REVISEDATE}.diff.gz

LIB_DEPENDS+=	hz.0:${PORTSDIR}/chinese/autoconvert

CFLAGS+=	-D_DONT_USE_CTYPE_INLINE_

WITH_MUTT_LOCALES_FIX=	yes
MUTT_CONFIGURE_ARGS+=	--without-wc-funcs
WITH_MUTT_NCURSES=	yes
WITH_MUTT_ASSUMED_CHARSET_PATCH=	yes
.if !defined(PACKAGE_BUILDING)
WITHOUT_MUTT_SGMLFORMAT=	yes
WITHOUT_MUTT_HTML=		yes
WITHOUT_MUTT_XML=		yes
WITHOUT_MUTT_COMPRESSED_FOLDERS=yes
.endif
MUTT_SLAVE_HTML_PAGES=	1

MD5_FILE=	${.CURDIR}/distinfo
PKGMESSAGE=	${.CURDIR}/pkg-message

.include "${MASTERDIR}/Makefile"
