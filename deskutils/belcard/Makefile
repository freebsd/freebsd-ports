PORTNAME=	belcard
DISTVERSION=	5.4.24
CATEGORIES=	deskutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	vCard support library
WWW=		https://www.linphone.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libbctoolbox.a:net/bctoolbox \
		${LOCALBASE}/lib/libbcunit.a:devel/bcunit \
		${LOCALBASE}/lib/libbelr.a:textproc/belr

USES=		cmake compiler:c++17-lang dos2unix ssl
DOS2UNIX_FILES=	${WRKSRC}/CMakeLists.txt
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STRICT=NO \
		-DENABLE_UNIT_TESTS=NO

LDFLAGS+=	-lpthread

.include <bsd.port.mk>
