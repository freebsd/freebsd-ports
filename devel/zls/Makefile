PORTNAME=	zls
DISTVERSION=	0.15.1
CATEGORIES=	devel

MAINTAINER=	kenrap@kennethraplee.com
COMMENT=	Zig LSP implementation + Zig Language Server
WWW=		https://github.com/zigtools/zls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${ZIG_CMD}:${ZIG_PORT}

USES=		zig

USE_GITHUB=	yes
GH_ACCOUNT=	zigtools

ZIG_TUPLE=	diffz:github.com/ziglibs/diffz/archive/a20dd1f11b10819a6f570f98b42e1c91e3704357.tar.gz:diffz-0.0.1-G2tlIQrOAQCfH15jdyaLyrMgV8eGPouFhkCeYFTmJaLk \
		known_folders:github.com/ziglibs/known-folders/archive/92defaee76b07487769ca352fd0ba95bc8b42a2f.tar.gz:known_folders-0.0.0-Fy-PJkfRAAAVdptXWXBspIIC7EkVgLgWozU5zIk5Zgcy \
		lsp_kit:github.com/zigtools/lsp-kit/archive/576e9405b1ab22c17c0f9318feed3278aa66b0ea.tar.gz:lsp_kit-0.1.0-bi_PL04yCgAxLsF0hH2a5sZKT84MGQaKXouw2jvCE8Nl \
		tracy:github.com/wolfpld/tracy/archive/refs/tags/v0.11.1.tar.gz:N-V-__8AAMeOlQEipHjcyu0TCftdAi9AQe7EXUDJOoVe0k-t

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
