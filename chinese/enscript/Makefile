# New ports collection makefile for:	zh Big5/GB-izedenscript (a4)
# Date created:		27 Nov, 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	chinese

MAINTAINER=	rafan@FreeBSD.org

RUN_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm

PAPERSIZE=	a4
MASTERDIR=	${.CURDIR}/../../print/enscript-letter

EXTRA_PATCHES=	${.CURDIR}/files/patch-*
PLIST=		${WRKDIR}/pkg-plist
PKGMESSAGE=	${.CURDIR}/pkg-message

USE_GHOSTSCRIPT_RUN=	yes

post-patch:
	@${ECHO_CMD} "share/enscript/README.BIG5" > ${WRKDIR}/pkg-plist
	@${CAT} ${MASTERDIR}/pkg-plist >> ${WRKDIR}/pkg-plist

post-install:
	@${INSTALL_DATA} ${.CURDIR}/files/README.BIG5 ${PREFIX}/share/enscript
	@${CAT} ${PKGMESSAGE}

.include "${MASTERDIR}/Makefile"
