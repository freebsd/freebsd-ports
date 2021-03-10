# Created by: Ka Ho Ng <khng300@gmail.com>
# $FreeBSD$

PORTNAME=	rime-bopomofo
DISTVERSION=	g20210131
CATEGORIES=	chinese textproc

MAINTAINER=	khng300@gmail.com
COMMENT=	Rime Chewing schema support

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	\
		rime_deployer:chinese/librime \
		zh-rime-essay>g0:chinese/rime-essay \
		zh-rime-prelude>g0:chinese/rime-prelude \
		zh-rime-terra-pinyin>g0:chinese/rime-terra-pinyin
RUN_DEPENDS=	\
		zh-rime-prelude>g0:chinese/rime-prelude	\
		zh-rime-terra-pinyin>g0:chinese/rime-terra-pinyin

USES=		localbase

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rime
GH_TAGNAME=	c7618f4f5728e1634417e9d02ea50d82b71956ab

NO_ARCH=	yes

PORTDOCS=	AUTHORS README.md

PRELUDE_FILES=	default.yaml key_bindings.yaml punctuation.yaml symbols.yaml
ESSAY_FILES=	essay.txt
TERRA_PINYIN_FILES=	terra_pinyin.dict.yaml
SCHEMA_FILES=	bopomofo.schema.yaml	\
		bopomofo_express.schema.yaml	\
		bopomofo_tw.schema.yaml
MY_OUTDIR=	${WRKDIR}/out

do-build:
	@${MKDIR} ${MY_OUTDIR}
	@${RLN} ${WRKSRC}/* ${MY_OUTDIR}
.for i in ${PRELUDE_FILES} ${ESSAY_FILES} ${TERRA_PINYIN_FILES}
	@${CP} ${LOCALBASE}/share/rime-data/${i} ${MY_OUTDIR}
.endfor
.for i in ${SCHEMA_FILES}
	rime_deployer --compile ${WRKSRC}/${i} ${MY_OUTDIR}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/rime-data
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/rime-data/build
	${INSTALL_DATA} ${WRKSRC}/*.yaml ${STAGEDIR}${PREFIX}/share/rime-data
	${INSTALL_DATA} ${MY_OUTDIR}/build/bopomofo*	\
		${STAGEDIR}${PREFIX}/share/rime-data/build

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/AUTHORS ${STAGEDIR}/${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
