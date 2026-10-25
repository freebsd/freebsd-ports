PORTNAME=	jbig2enc
DISTVERSION=	0.32
CATEGORIES=	graphics devel

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	JBIG2 Encoder
WWW=		https://github.com/agl/jbig2enc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libleptonica.so:graphics/leptonica

USES=		autoreconf gmake compiler:c++17-lang libtool:build \
		localbase pkgconfig:build python:build,run shebangfix
SHEBANG_FILES=	jbig2topdf.py
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	agl
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
