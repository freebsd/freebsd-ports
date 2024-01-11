PORTNAME=	lha
PORTVERSION=	1.14i
PORTREVISION=	10
CATEGORIES=	archivers
MASTER_SITES=	http://www2m.biglobe.ne.jp/~dolphin/lha/prog/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Archive files using LZSS and Huffman compression (.lzh files)
WWW=		http://www2m.biglobe.ne.jp/~dolphin/lha/lha.htm

LICENSE=	LHA
LICENSE_NAME=	License of lha
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe
CPE_VENDOR=	tsugio_okamoto

PLIST_FILES=	bin/lha
PLIST_FILES+=	share/man/ja/man1/lha.1.gz
PLIST_FILES+=	share/${UNIQUE_PREFIX}${PORTNAME}/lha-114i.tar.gz
.if !defined(DISABLE_LICENSES)
PLIST_FILES+=	share/licenses/${PKGNAME}/LICENSE.en
.endif

do-install:
	-${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ja/man1 \
		${STAGEDIR}${DATADIR} ${STAGEDIR}${_LICENSE_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/lha.n ${STAGEDIR}${PREFIX}/share/man/ja/man1/lha.1
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${DATADIR}/
.if !defined(DISABLE_LICENSES)
	${INSTALL_DATA} ${FILESDIR}/LICENSE.en ${STAGEDIR}${_LICENSE_DIR}/
.endif

.include <bsd.port.mk>
