PORTNAME=	belcard
DISTVERSION=	5.4.28
CATEGORIES=	deskutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	vCard support library
WWW=		https://www.linphone.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbcunit.so:devel/bcunit \
		libbelr.so:textproc/belr

USES=		cmake compiler:c++17-lang dos2unix ssl
DOS2UNIX_FILES=	${WRKSRC}/CMakeLists.txt
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_UNIT_TESTS

LDFLAGS+=	-lpthread

.include <bsd.port.mk>
