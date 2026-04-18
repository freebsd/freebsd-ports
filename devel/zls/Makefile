PORTNAME=	zls
DISTVERSION=	0.16.0
CATEGORIES=	devel

MAINTAINER=	kenrap@FreeBSD.org
COMMENT=	Zig LSP implementation + Zig Language Server
WWW=		https://github.com/zigtools/zls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${ZIG_CMD}:${ZIG_PORT}

USES=		zig

USE_GITHUB=	yes
GH_ACCOUNT=	zigtools

ZIG_TUPLE= diffz:github.com/ziglibs/diffz/archive/b39fe07e7fdbcf56e43ba2890b9f484f16969f90.tar.gz:diffz-0.0.1-G2tlISzNAQCldmOcINavGmF1zdt20NFPXeM8d07jp_68 \
		known_folders:github.com/ziglibs/known-folders/archive/d6d03830968cca6b7b9f24fd97ee348346a6905d.tar.gz:known_folders-0.0.0-Fy-PJk3KAACzUg2us_0JvQQmod1ZA8jBt7MuoKCihq88 \
		lsp_kit:github.com/zigtools/lsp-kit/archive/b886a2b0d5cee85ecbcc3089b863f7517cc9ff7f.tar.gz:lsp_kit-0.1.0-bi_PL3IyDACfp1xdTnkiOHEok2YpPCCCJHuuOcNzjl1D \
		tracy:github.com/wolfpld/tracy/archive/refs/tags/v0.13.1.tar.gz:N-V-__8AAOncKwEm1F9c5LrT7HMNmRMYX8-fAoqpc6YyTu9X

PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Respect PREFIX for global_configuration
	${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' ${WRKSRC_known_folders}/known-folders.zig

.include <bsd.port.mk>
