PORTNAME=	skk-jawiki
DISTVERSION=	2026.04.01.141931
CATEGORIES=	japanese
MASTER_SITES=	https://github.com/tokuhirom/jawiki-kana-kanji-dict/releases/download/v${DISTVERSION}/
DISTFILES=	SKK-JISYO.jawiki

MAINTAINER=	mce@FreeBSD.org
COMMENT=	SKK dictionary from Wikipedia (Japanese edition)
WWW=		https://github.com/tokuhirom/jawiki-kana-kanji-dict

LICENSE=	MIT

NO_ARCH=	yes

SKKDIR=		share/skk
SKKDIC=		SKK-JISYO.jawiki

PLIST_FILES=	${DICS:S|^|${SKKDIR}/|}

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

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SKKDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DICS} ${STAGEDIR}${PREFIX}/${SKKDIR}

.include <bsd.port.mk>
