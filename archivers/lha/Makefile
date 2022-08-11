PORTNAME=	lha
PORTVERSION=	1.14i
PORTREVISION=	8
CATEGORIES=	archivers
MASTER_SITES=	http://www2m.biglobe.ne.jp/~dolphin/lha/prog/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Archive files using LZSS and Huffman compression (.lzh files)

LICENSE=	LHA
LICENSE_NAME=	License of lha
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell auto-accept

USES=		cpe
CPE_VENDOR=	tsugio_okamoto

PLIST_FILES=	bin/lha
PLIST_FILES+=	man/ja/man1/lha.1.gz

do-install:
	-${MKDIR} ${STAGEDIR}${PREFIX}/man/ja/man1
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/lha.n ${STAGEDIR}${PREFIX}/man/ja/man1/lha.1

.include <bsd.port.mk>
