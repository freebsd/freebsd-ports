PORTNAME=	cgif
PORTVERSION=	0.3.2
DISTVERSIONPREFIX=	V
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GIF encoder written in C
WWW=		https://github.com/dloebl/cgif

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson

MESON_ARGS=	--default-library=both -Dtests=true

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	dloebl

.include <bsd.port.mk>
