PORTNAME=	fcitx5-karukan
DISTVERSION=	g20260816
CATEGORIES=	japanese textproc

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Japanese input method for fcitx5 powered by neural kana-kanji conversion
WWW=		https://github.com/togatoga/karukan

LICENSE=		APACHE20 MIT
LICENSE_COMB=		dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BROKEN_i386=	fails to build: cannot find function `_mm256_insert_epi64` in this scope

LIB_DEPENDS=	libonig.so:devel/oniguruma \
		libFcitx5Core.so:textproc/fcitx5 \
		libxkbcommon.so:x11/libxkbcommon

USES=		cargo cmake:noninja gmake kde llvm localbase:ldflags pkgconfig \
		ssl

USE_GITHUB=	yes
GH_ACCOUNT=	togatoga
GH_PROJECT=	karukan
GH_TAGNAME=	5e1b5411a681c26a9b8bc1f5905035781c0d5bb2

USE_KDE=	ecm:build

CMAKE_OFF=		KARUKAN_NATIVE
CMAKE_SOURCE_PATH=	${WRKSRC}/karukan-im/fcitx5/fcitx5-addon

CARGO_CARGOTOML=	${WRKSRC}/Cargo.toml
CARGO_CARGOLOCK=	${WRKSRC}/Cargo.lock
CARGO_BUILD=		no
CARGO_BUILD_ARGS=	--package karukan-cli
CARGO_INSTALL=		no
CARGO_TEST=		no

RUSTFLAGS=		-C link-arg=-lomp

PORTDOCS=	README.md \
		README-karukan-cli.md \
		README-karukan-engine.md \
		README-karukan-im-fcitx5.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|/usr|${PREFIX}|" \
		${WRKSRC}/karukan-cli/src/bin/server.rs

post-build:
	${CARGO_CARGO_RUN} build --manifest-path=${CARGO_CARGOTOML} \
		--verbose --verbose \
		${CARGO_BUILD_ARGS}

post-install:
.for prog in ajimee-bench karukan-dict karukan-server sudachi-dict
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/*/${prog} \
		${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/karukan
	cd ${WRKSRC}/karukan-cli && \
	${COPYTREE_SHARE} static ${STAGEDIR}${PREFIX}/share/karukan
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fcitx5/karukan
.for f in default.toml default_user_dict.txt
	${INSTALL_DATA} ${WRKSRC}/karukan-im/core/config/${f} \
		${STAGEDIR}${PREFIX}/share/fcitx5/karukan
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.for dir in karukan-cli karukan-engine karukan-im/fcitx5
	${INSTALL_MAN} ${WRKSRC}/${dir}/README.md \
		${STAGEDIR}${DOCSDIR}/README-${dir:S|/|-|}.md
.endfor

.include <bsd.port.mk>
