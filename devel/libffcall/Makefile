PORTNAME=	libffcall
DISTVERSION=	2.5
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	ndowens04@gmail.com
COMMENT=	Foreign function call libraries
WWW=		https://www.gnu.org/software/libffcall/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CONFIGURE_ARGS=		--enable-shared
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	check
CFLAGS+=		-fPIC

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libavcall.so \
		${STAGEDIR}${PREFIX}/lib/libcallback.so \
		${STAGEDIR}${PREFIX}/lib/libtrampoline.so

.include <bsd.port.mk>
