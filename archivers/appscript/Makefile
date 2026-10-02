PORTNAME=	appscript
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	archivers

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Simple, lightweight and effective tool for creating SFX files

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	signify:security/signify

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/appscript \
		bin/appscript-verify \
		share/appscript/stub.c \
		share/man/man1/appscript-verify.1.gz \
		share/man/man1/appscript.1.gz

OPTIONS_DEFINE=		BLAKE3
OPTIONS_DEFAULT=	BLAKE3

BLAKE3_DESC=		Enable support for Blake3
BLAKE3_RUN_DEPENDS=	b3sum:sysutils/b3sum

.include <bsd.port.mk>
