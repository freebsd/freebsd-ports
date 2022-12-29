PORTNAME=	turbo
PORTVERSION=	g20221121
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Text editor based on Scintilla and Turbo Vision
WWW=		https://github.com/magiblot/turbo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libclipboard.so:x11/libclipboard \
		libfmt.so:devel/libfmt

USES=		cmake compiler:c++17-lang xorg
USE_GITHUB=	yes
USE_XORG=	xcb

GH_ACCOUNT=	magiblot
GH_PROJECT=	tvision:tv
GH_TAGNAME=	3e3a0db 0675ade:tv
GH_SUBDIR=	deps/tvision:tv

CMAKE_ON=	TURBO_USE_SYSTEM_DEPS

.include <bsd.port.mk>
