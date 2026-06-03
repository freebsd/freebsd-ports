PORTNAME=	mecab-jawiki
DISTVERSION=	2026.04.01.141931
CATEGORIES=	japanese
MASTER_SITES=	https://github.com/tokuhirom/jawiki-kana-kanji-dict/releases/download/v${DISTVERSION}/
DISTFILES=	mecab-userdic.csv

MAINTAINER=	mce@FreeBSD.org
COMMENT=	MeCab dictionary from Wikipedia (Japanese edition)
WWW=		https://github.com/tokuhirom/jawiki-kana-kanji-dict

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/libexec/mecab/mecab-dict-index:japanese/mecab

NO_ARCH=	yes

MECABDIR=	lib/mecab/dic/ipadic
MECABDIC=	jawiki.dic

PLIST_FILES=	${MECABDIR}/${MECABDIC}

OPTIONS_DEFAULT=	UTF8
OPTIONS_SINGLE=		CHARSET
OPTIONS_SINGLE_CHARSET=	EUCJP SHIFTJIS UTF8
EUCJP_DESC=		Use EUC-JP as dictionary charset
SHIFTJIS_DESC=		Use SHIFT-JIS as dictionary charset
UTF8_DESC=		Use UTF-8 as dictionary charset

EUCJP_BUILD_DEPENDS=	ja-mecab-ipadic-eucjp>0:japanese/mecab-ipadic-eucjp
EUCJP_VARS=		CSET=euc-jp
SHIFTJIS_BUILD_DEPENDS=	ja-mecab-ipadic-sjis>0:japanese/mecab-ipadic-sjis
SHIFTJIS_VARS=		CSET=shiftjis
UTF8_BUILD_DEPENDS=	ja-mecab-ipadic-utf8>0:japanese/mecab-ipadic-utf8
UTF8_VARS=		CSET=utf-8

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	${LOCALBASE}/libexec/mecab/mecab-dict-index \
		-d ${LOCALBASE}/${MECABDIR} -u ${WRKSRC}/${MECABDIC} \
		-f utf-8 -t ${CSET} ${WRKSRC}/${DISTFILES}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${MECABDIR}
	${INSTALL_DATA} ${WRKSRC}/${MECABDIC} ${STAGEDIR}${PREFIX}/${MECABDIR}

.include <bsd.port.mk>
