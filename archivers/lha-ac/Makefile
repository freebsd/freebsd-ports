# $FreeBSD$

PORTNAME=	lha
PORTVERSION=	1.14i
PORTREVISION=	10
CATEGORIES=	archivers
MASTER_SITES=	OSDN/lha
PKGNAMESUFFIX=	-ac${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-${PORTVERSION}-ac20050924p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Archive files using LZSS and Huffman compression (.lzh files)

RESTRICTED=	No redistribution allowed

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/lha-ac
PLIST_FILES+=	man/ja/man1/lha-ac.1.gz

OPTIONS_DEFINE=	NLS
NLS_CONFIGURE_ON=	--enable-multibyte-filename=auto
NLS_CONFIGURE_OFF=	--disable-multibyte-filename

do-install:
	-${MKDIR} ${STAGEDIR}${PREFIX}/man/ja/man1
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${STAGEDIR}${PREFIX}/bin/lha-ac
	${INSTALL_MAN} ${WRKSRC}/man/lha.n ${STAGEDIR}${PREFIX}/man/ja/man1/lha-ac.1

.include <bsd.port.mk>
