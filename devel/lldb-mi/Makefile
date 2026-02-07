PORTNAME=	lldb-mi
DISTVERSION=	g20250923
CATEGORIES=	devel lang

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Machine interface driver for the LLDB debugger
WWW=		https://lldb.llvm.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		cmake llvm:lib,noexport

USE_GITHUB=	yes
GH_ACCOUNT=	lldb-tools
GH_TAGNAME=	31ed003a15a4a8e44881401d065217dfb2642406

PLIST_FILES=	bin/lldb-mi

.include <bsd.port.mk>
