PORTNAME=	stylua
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
PORTREVISION=	5
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Opinionated Lua code formatter
WWW=		https://github.com/JohnnyMorganz/StyLua

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	JohnnyMorganz
GH_PROJECT=	StyLua

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS EDITORCONFIG LUAU
OPTIONS_DEFAULT=	EDITORCONFIG LUAU

EDITORCONFIG_DESC=	Build with EditorConfig support
LUAU_DESC=		Build with Luau support

EDITORCONFIG_VARS=	CARGO_FEATURES+=editorconfig
LUAU_VARS=		CARGO_FEATURES+=luau

.for _ver in 5.2 5.3 5.4
OPTIONS_DEFINE+=	LUA${_ver:C/\.//}
OPTIONS_DEFAULT+=	LUA${_ver:C/\.//}
LUA${_ver:C/\.//}_DESC=	Build with Lua ${_ver} support
LUA${_ver:C/\.//}_VARS=	CARGO_FEATURES+=lua${_ver:C/\.//}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
