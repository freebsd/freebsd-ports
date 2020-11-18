# $FreeBSD$

PORTEPOCH=	0 # don't bump accidentally
PKGNAMESUFFIX=	-static

COMMENT=	Small, fast Emacs-like editor (rescue(8) version)

MASTERDIR=	${.CURDIR}/../mg

CONFIGURE_ARGS=	--enable-static
PLIST_FILES=	/rescue/${PORTNAME}

OPTIONS_EXCLUDE=DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PLIST_FILES:[1]:H}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PLIST_FILES:[1]}

.include "${MASTERDIR}/Makefile"
