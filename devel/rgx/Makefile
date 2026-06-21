PORTNAME=	rgx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.1
CATEGORIES=	devel

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Regex debugger for the terminal
WWW=		https://github.com/brevity1swos/rgx

LICENSE=	APACHE20 BSL MIT MPL20 UNICODE UNLICENSE WTFPL ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_UNICODE=	UNICODE, INC. LICENSE AGREEMENT - DATA FILES AND SOFTWARE
LICENSE_NAME_UNICODE-DFS-2016=	Unicode License Agreement - Data Files and Software (2016)
LICENSE_TEXT_UNICODE=	See https://www.unicode.org/copyright.html
LICENSE_TEXT_UNICODE-DFS-2016=	See https://spdx.org/licenses/Unicode-DFS-2016.html
LICENSE_PERMS_UNICODE=		dist-mirror dist-sell pkg-mirror pkg-sell \
				auto-accept
LICENSE_PERMS_UNICODE-DFS-2016=	dist-mirror dist-sell pkg-mirror pkg-sell \
				auto-accept

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	brevity1swos

OPTIONS_DEFINE=	DOCS PCRE2

PCRE2_DESC=	${PCRE_DESC} (version 2)

PCRE2_LIB_DEPENDS=	libpcre2-posix.so:devel/pcre2
PCRE2_VARS=		CARGO_FEATURES+=pcre2-engine

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
