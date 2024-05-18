PORTNAME=	lldb-mi
DISTVERSION=	g20231216
CATEGORIES=	devel lang

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Machine interface driver for the LLDB debugger
WWW=		https://lldb.llvm.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake llvm:lib,noexport

USE_GITHUB=	yes
GH_ACCOUNT=	lldb-tools
GH_TAGNAME=	a6c8c66d70b13209f3dabba5b6aefb2c58c3976c

PLIST_FILES=	bin/lldb-mi

.include <bsd.port.mk>
