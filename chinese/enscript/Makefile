# New ports collection makefile for:	zh Big5/GB-izedenscript (a4)
# Date created:		27 Nov, 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	chinese

PAPERSIZE=	a4
MASTERDIR=	${.CURDIR}/../../print/enscript-letter

MAINTAINER=	keith@FreeBSD.org

RUN_DEPENDS=	ttfm.sh:${PORTSDIR}/chinese/ttfm \
		gs:${PORTSDIR}/print/ghostscript-gnu

EXTRA_PATCHES=	${.CURDIR}/files/patch-*
PLIST=		${WRKDIR}/pkg-plist
PKGMESSAGE=	${.CURDIR}/pkg-message

post-patch:
	@${ECHO_CMD} "share/enscript/README.BIG5" > ${WRKDIR}/pkg-plist
	@${CAT} ${MASTERDIR}/pkg-plist >> ${WRKDIR}/pkg-plist

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	@${INSTALL_DATA} ${.CURDIR}/files/README.BIG5 ${PREFIX}/share/enscript
	@${CAT} ${PKGMESSAGE}

.include "${MASTERDIR}/Makefile"
