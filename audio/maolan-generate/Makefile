PORTNAME=	maolan-generate
DISTVERSION=	0.0.24
CATEGORIES=	audio

MAINTAINER=	meka@sys.it.com
COMMENT=	Maolan AI for generating music
WWW=		https://maolan.rs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	requires 64-bit architecture

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	maolan
GH_PROJECT=	generate

PLIST_FILES=	bin/maolan-generate \
		share/man/man1/maolan-generate.1.gz

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/maolan-generate.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
