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

# XXX: Currently PORTREVISION assignment is not functional. Master port
# needs to be fixed.

MAINTAINER=	clive@FreeBSD.org
COMMENT=	The Mongrel of Mail User Agents with Chinese support

PATCH_SITES=	http://bsdchat.com/~clive/dist/mutt15/ \
		ftp://freebsd.sinica.edu.tw/pub/clive/mutt15/
PATCHFILES=	${PKGNAMEPREFIX}mutt-${PORTVERSION}-${REVISEDATE}.diff.gz

LIB_DEPENDS+=	hz.0:${PORTSDIR}/chinese/autoconvert

CFLAGS+=	-D_DONT_USE_CTYPE_INLINE_

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
