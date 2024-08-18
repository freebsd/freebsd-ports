PORTNAME=	jawiki
DISTVERSION=	g20240521
CATEGORIES=	japanese
PKGNAMEPREFIX?=	ja-skk-

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT?=	SKK dictionary from Wikipedia (Japanese edition)
WWW=		https://github.com/tokuhirom/jawiki-kana-kanji-dict

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	tokuhirom
GH_PROJECT=	jawiki-kana-kanji-dict
GH_TAGNAME=	d62e22e
NO_ARCH=	yes

.if defined(MECAB)
BUILD_DEPENDS=	${LOCALBASE}/libexec/mecab/mecab-dict-index:japanese/mecab

MECABDIR=	lib/mecab/dic/ipadic
MECABDIC=	${PORTNAME}.dic

PLIST_FILES=	${MECABDIR}/${MECABDIC}

OPTIONS_DEFAULT=	UTF8
OPTIONS_SINGLE=		CHARSET
OPTIONS_SINGLE_CHARSET=	EUCJP SHIFTJIS UTF8
EUCJP_DESC=		Use EUC-JP as dictionary charset.
SHIFTJIS_DESC=		Use SHIFT-JIS as dictionary charset.
UTF8_DESC=		Use UTF-8 as dictionary charset.

EUCJP_BUILD_DEPENDS=	ja-mecab-ipadic-eucjp>0:japanese/mecab-ipadic-eucjp
SHIFTJIS_BUILD_DEPENDS=	ja-mecab-ipadic-sjis>0:japanese/mecab-ipadic-sjis
UTF8_BUILD_DEPENDS=	ja-mecab-ipadic-utf8>0:japanese/mecab-ipadic-utf8

EUCJP_VARS=		CSET=euc-jp
SHIFTJIS_VARS=		CSET=shiftjis
UTF8_VARS=		CSET=utf-8

do-build:
	${LOCALBASE}/libexec/mecab/mecab-dict-index \
		-d ${LOCALBASE}/${MECABDIR} -u ${WRKSRC}/${MECABDIC} \
		-f utf-8 -t ${CSET} ${WRKSRC}/mecab-userdic.csv

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${MECABDIR}
	${INSTALL_DATA} ${WRKSRC}/${MECABDIC} ${STAGEDIR}${PREFIX}/${MECABDIR}
.else
SKKDIR=		share/skk
SKKDIC=		SKK-JISYO.${PORTNAME}

OPTIONS_DEFAULT=		EUCCDB
OPTIONS_MULTI=			DICTIONARY
OPTIONS_MULTI_DICTIONARY=	EUC EUCCDB UTF8 UTF8CDB
EUC_DESC=			EUC-JP Charset dictionary
EUCCDB_DESC=			EUC-JP Charset dictionary (cdb)
UTF8_DESC=			UTF8 Charset dictionary
UTF8CDB_DESC=			UTF8 Charset dictionary (cdb)

EUC_BUILD_DEPENDS=		${LOCALBASE}/bin/nkf:japanese/nkf
EUCCDB_BUILD_DEPENDS=		${LOCALBASE}/bin/nkf:japanese/nkf \
				${LOCALBASE}/bin/cdb:databases/tinycdb
UTF8CDB_BUILD_DEPENDS=		${LOCALBASE}/bin/cdb:databases/tinycdb

EUC_VARS=			DICS=${SKKDIC}
EUCCDB_VARS=			DICS+=${SKKDIC}.cdb
UTF8_VARS=			DICS+=${SKKDIC}.utf8
UTF8CDB_VARS=			DICS+=${SKKDIC}.utf8.cdb

PLIST_FILES=	${DICS:S|^|${SKKDIR}/|}

.include <bsd.port.options.mk>

do-build:
	${MV} ${WRKSRC}/${SKKDIC} ${WRKSRC}/${SKKDIC}.orig
.if ${PORT_OPTIONS:MUTF8*}
	${ECHO_CMD} ';; -*- mode: fundamental; coding: utf-8 -*-' | \
		${CAT} - ${WRKSRC}/${SKKDIC}.orig > ${WRKSRC}/${SKKDIC}.utf8
.endif
.if ${PORT_OPTIONS:MEUC*}
	${ECHO_CMD} ';; -*- mode: fundamental; coding: euc-jp -*-' \
		> ${WRKSRC}/${SKKDIC}
	${LOCALBASE}/bin/nkf --oc=eucJP-ms ${WRKSRC}/${SKKDIC}.orig \
		>> ${WRKSRC}/${SKKDIC}
.endif
.for dic in ${DICS:M*.cdb}
	${AWK} '/^[^;]/ { \
			s = substr($$0, index($$0, " ") + 1); \
			print "+" length($$1) "," length(s) ":" $$1 "->" s; \
		} \
		END { \
			print ""; \
		}' < ${WRKSRC}/${dic:S|.cdb||} | \
	${LOCALBASE}/bin/cdb -c -t - ${WRKSRC}/${dic}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SKKDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DICS} ${STAGEDIR}${PREFIX}/${SKKDIR}
.endif

.include <bsd.port.mk>
