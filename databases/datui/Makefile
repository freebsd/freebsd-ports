PORTNAME=	datui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.55
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Data exploration in the terminal
WWW=		https://derekwisong.github.io/datui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libzstd.so:archivers/zstd

USES=		cargo pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	derekwisong

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-install:
	${INSTALL_MAN} ${CARGO_TARGET_DIR}/release/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
