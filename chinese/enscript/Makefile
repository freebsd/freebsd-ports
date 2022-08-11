PORTREVISION=	3
CATEGORIES=	chinese

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	ttfm.sh:chinese/ttfm

PAPERSIZE=	a4
MASTERDIR=	${.CURDIR}/../../print/enscript-letter

EXTRA_PATCHES=	${.CURDIR}/files/patch-*
PLIST=		${WRKDIR}/pkg-plist
PKGMESSAGE=	${.CURDIR}/pkg-message

USES+=		ghostscript:run

CONFLICTS_INSTALL=	enscript-a4 enscript-letter enscript-letterdj # bin/einfo bin/xml2json

post-patch:
	@${ECHO_CMD} "share/enscript/README.BIG5" > ${WRKDIR}/pkg-plist
	@${CAT} ${MASTERDIR}/pkg-plist >> ${WRKDIR}/pkg-plist

post-install:
	@${INSTALL_DATA} ${.CURDIR}/files/README.BIG5 ${STAGEDIR}${PREFIX}/share/enscript

.include "${MASTERDIR}/Makefile"
