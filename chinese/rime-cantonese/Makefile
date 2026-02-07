PORTNAME=	rime-cantonese
DISTVERSION=	g20241130
CATEGORIES=	chinese textproc

MAINTAINER=	eric@camachat.org
COMMENT=	Rime Cantonese (Jyutping) schema support
WWW=		https://github.com/rime/rime-cantonese

LICENSE=		CC-BY-4.0 ODbL
LICENSE_COMB=		multi
LICENSE_FILE_CC-BY-4.0=	${WRKSRC}/LICENSE-CC-BY
LICENSE_FILE_ODbL=	${WRKSRC}/LICENSE-ODbL

BUILD_DEPENDS=	\
		rime_deployer:chinese/librime \
		zh-rime-essay>g0:chinese/rime-essay \
		zh-rime-prelude>g0:chinese/rime-prelude
RUN_DEPENDS=	zh-rime-prelude>g0:chinese/rime-prelude

USES=		localbase

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rime
GH_TAGNAME=	ac277184f161f297c2031b497588975234019f9d

NO_ARCH=	yes

PORTDOCS=	README.md README-cmn.md README-en.md demo/*

PRELUDE_FILES=	default.yaml key_bindings.yaml punctuation.yaml symbols.yaml
ESSAY_FILES=	essay.txt
SCHEMA_FILES=	jyut6ping3.schema.yaml jyut6ping3_ipa.schema.yaml
MY_OUTDIR=	${WRKDIR}/out

do-build:
	@${MKDIR} ${MY_OUTDIR}
	@${RLN} ${WRKSRC}/* ${MY_OUTDIR}
.for i in ${PRELUDE_FILES} ${ESSAY_FILES}
	@${CP} ${LOCALBASE}/share/rime-data/${i} ${MY_OUTDIR}
.endfor
.for i in ${SCHEMA_FILES}
	rime_deployer --compile ${WRKSRC}/${i} ${MY_OUTDIR}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/rime-data
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/rime-data/opencc
	${INSTALL_DATA} ${WRKSRC}/opencc/* ${STAGEDIR}${PREFIX}/share/rime-data/opencc
	${INSTALL_DATA} ${WRKSRC}/*.yaml ${STAGEDIR}${PREFIX}/share/rime-data
	(cd ${MY_OUTDIR} && ${COPYTREE_SHARE} build ${STAGEDIR}${PREFIX}/share/rime-data)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/* ${STAGEDIR}${DOCSDIR}/demo
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README-cmn.md ${STAGEDIR}/${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README-en.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
