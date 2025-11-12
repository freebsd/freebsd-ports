PORTNAME=	lha
PORTVERSION=	1.14i.20250923
CATEGORIES=	archivers
PKGNAMESUFFIX=	-ac

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Archive files using LZSS and Huffman compression (.lzh files)
WWW=		https://github.com/jca02266/lha

# Converted from RESTRICTED
LICENSE=	LHA
LICENSE_NAME=	LHA
LICENSE_TEXT=	No redistribution allowed
LICENSE_PERMS=	auto-accept

USES=		autoreconf cpe
CPE_VENDOR=	tsugio_okamoto

USE_GITHUB=	yes
GH_ACCOUNT=	jca02266
GH_TAGNAME=	0a07ec7

GNU_CONFIGURE=	yes

TEST_TARGET=	check

PLIST_FILES=	bin/lha-ac \
		share/man/ja/man1/lha-ac.1.gz \
		share/man/man1/lha-ac.1.gz

OPTIONS_DEFINE=		NLS
NLS_CONFIGURE_ON=	--enable-multibyte-filename=auto
NLS_CONFIGURE_OFF=	--disable-multibyte-filename

do-install:
	-${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ja/man1
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${STAGEDIR}${PREFIX}/bin/lha-ac
	${INSTALL_MAN} ${WRKSRC}/man/lha.1 ${STAGEDIR}${PREFIX}/share/man/man1/lha-ac.1
	${INSTALL_MAN} ${WRKSRC}/man/lha.n ${STAGEDIR}${PREFIX}/share/man/ja/man1/lha-ac.1

.include <bsd.port.mk>
