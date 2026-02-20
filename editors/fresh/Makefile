PORTNAME=	fresh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.5
CATEGORIES=	editors

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Terminal based IDE & text editor: easy, powerful and fast
WWW=		https://getfresh.dev

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../../LICENSE

BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	sinelaw

WRKSRC_SUBDIR=	crates/fresh-editor

PLIST_FILES=	bin/fresh

.include <bsd.port.mk>
