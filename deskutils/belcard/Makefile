PORTNAME=	belcard
DISTVERSION=	5.1.32
CATEGORIES=	deskutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	vCard support library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbelr.so:textproc/belr

USES=		cmake compiler:c++11-lib
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_COMMIT=	c7b1b58765bf5c99822025e77d0bc13cea82c719
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DENABLE_STATIC=NO \
		-DENABLE_STRICT=NO \
		-DENABLE_UNIT_TESTS=NO

.include <bsd.port.mk>
