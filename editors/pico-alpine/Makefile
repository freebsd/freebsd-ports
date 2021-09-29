PORTNAME=	pico-alpine
PORTREVISION=	0
CATEGORIES=	editors
DISTNAME=	alpine-${PORTVERSION}

COMMENT=	[Al]PIne's message COmposition editor and Pilot file manager

MASTERDIR=	${.CURDIR}/../../mail/alpine

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PATCHDIR=			# To void equivalent in master port
PKGMESSAGE=	/nonexistent	# To void equivalent in master port
PKGINSTALL=	/nonexistent	# To void equivalent in master port
CPE_PRODUCT=	alpine

PICO_ALPINE_SLAVE=	yes

post-patch:
	@${CP} ${WRKSRC}/imap/Makefile ${WRKSRC}/imap/Makefile.presed
	@${SED}	-e "s#^\(all:.*\) bundled\$$#\1#" \
		${WRKSRC}/imap/Makefile.presed > ${WRKSRC}/imap/Makefile
	@${CP} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.presed
	@${SED}	-e "s#^\(SUBDIRS.*pico\).*#\1#" \
		-e "s#^man_MANS.*#man_MANS = doc/man1/pico.1 doc/man1/pilot.1#" \
		${WRKSRC}/Makefile.in.presed > ${WRKSRC}/Makefile.in

.include "${MASTERDIR}/Makefile"
