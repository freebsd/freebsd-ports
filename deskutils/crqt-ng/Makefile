PORTNAME=	crqt-ng
DISTVERSION=	1.0.15
CATEGORIES=	deskutils

MAINTAINER=	kenrap@kennethraplee.com
COMMENT=	E-book reader
WWW=		https://gitlab.com/coolreader-ng/crqt-ng

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcrengine-ng.so:deskutils/crengine-ng

USES=		qt:6 cmake desktop-file-utils pkgconfig

USE_GITLAB=	yes
GL_ACCOUNT=	coolreader-ng

USE_QT=		base translations

CMAKE_ARGS=	-D DOC_DATA_COMPRESSION_LEVEL=3 \
		-D USE_QT=QT6 \
		-D MAX_IMAGE_SCALE_MUL=2

OPTIONS_DEFINE= NLS
OPTIONS_SUB=    yes

.include <bsd.port.mk>
