# $FreeBSD$

PKGNAMESUFFIX=	-codec-rar
PORTREVISION=	0

COMMENT=	RAR decoder codec for p7zip

LICENSE=		LGPL21 UNRAR
LICENSE_COMB=		multi
LICENSE_NAME_UNRAR=	unRAR usage restriction license
LICENSE_FILE_UNRAR=	${WRKSRC}/DOCS/unRarLicense.txt
LICENSE_PERMS_UNRAR=	dist-mirror dist-sell pkg-mirror pkg-sell

MASTERDIR=	${.CURDIR}/../p7zip
ALL_TARGET=	common7z
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

OPTIONS_EXCLUDE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/p7zip/Codecs
	${INSTALL_LIB} ${WRKSRC}/bin/Codecs/Rar29.so ${STAGEDIR}${PREFIX}/libexec/p7zip/Codecs

.include "${MASTERDIR}/Makefile"
