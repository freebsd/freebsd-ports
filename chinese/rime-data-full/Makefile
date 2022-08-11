PORTNAME=	rime-data-full
PORTVERSION=	g20211129
CATEGORIES=	chinese textproc

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Rime data files full set

LICENSE=	GPLv3 LGPL3 APACHE20
LICENSE_COMB=	multi

RUN_DEPENDS=	\
	${_SCHEMA_DEPENDS} \
	${LOCALBASE}/share/rime-data/array30.schema.yaml:chinese/rime-array \
	${LOCALBASE}/share/rime-data/jyut6ping3.schema.yaml:chinese/rime-cantonese \
	${LOCALBASE}/share/rime-data/combo_pinyin.schema.yaml:chinese/rime-combo-pinyin \
	${LOCALBASE}/share/rime-data/double_pinyin.schema.yaml:chinese/rime-double-pinyin \
	${LOCALBASE}/share/rime-data/emoji_suggestion.yaml:chinese/rime-emoji \
	${LOCALBASE}/share/rime-data/ipa_xsampa.schema.yaml:chinese/rime-ipa \
	${LOCALBASE}/share/rime-data/yale.schema.yaml:chinese/rime-jyutping \
	${LOCALBASE}/share/rime-data/sampheng.schema.yaml:chinese/rime-middle-chinese \
	${LOCALBASE}/share/rime-data/pinyin_simp.schema.yaml:chinese/rime-pinyin-simp \
	${LOCALBASE}/share/rime-data/quick5.schema.yaml:chinese/rime-quick \
	${LOCALBASE}/share/rime-data/scj6.schema.yaml:chinese/rime-scj \
	${LOCALBASE}/share/rime-data/soutzoe.schema.yaml:chinese/rime-soutzoe \
	${LOCALBASE}/share/rime-data/stenotype.schema.yaml:chinese/rime-stenotype \
	${LOCALBASE}/share/rime-data/wubi86.schema.yaml:chinese/rime-wubi \
	${LOCALBASE}/share/rime-data/wugniu.schema.yaml:chinese/rime-wugniu

_SCHEMA_DEPENDS=	\
	${LOCALBASE}/share/rime-data/luna_pinyin.schema.yaml:chinese/rime-luna-pinyin	\
	${LOCALBASE}/share/rime-data/bopomofo.schema.yaml:chinese/rime-bopomofo	\
	${LOCALBASE}/share/rime-data/cangjie5.schema.yaml:chinese/rime-cangjie	\
	${LOCALBASE}/share/rime-data/stroke.schema.yaml:chinese/rime-stroke

USES=		localbase metaport

.include <bsd.port.mk>
