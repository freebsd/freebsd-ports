PORTNAME=	openssl
PORTVERSION=	1.0.2u
PORTREVISION=	1
CATEGORIES=	devel security
MASTER_SITES=	https://www.openssl.org/source/old/${PORTVERSION:C/[a-z]*$//}/ \
		http://artfiles.org/openssl.org/source/old/${PORTVERSION:C/[a-z]*$//}/
PKGNAMEPREFIX=	mingw32-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The OpenSSL library cross-compiled for MinGW32
WWW=		http://sctp.fh-muenster.de/dtls-patches.html

BUILD_DEPENDS=	makedepend:devel/makedepend \
		${PKGNAMEPREFIX}gcc:devel/${PKGNAMEPREFIX}gcc \
		${LOCALBASE}/mingw32/include/stdlib.h:devel/${PKGNAMEPREFIX}bin-msvcrt \
		${LOCALBASE}/mingw32/lib/libz.a:devel/mingw32-zlib

USES=		cpe perl5 shebangfix
SHEBANG_FILES=	apps/tsget
USE_PERL5=	build
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_PREFIX=	${PREFIX}/mingw32
OPENSSLDIR=		${CONFIGURE_PREFIX}/openssl
INSTALL_TARGET=		install_sw

post-patch:
	@${REINPLACE_CMD} -e 's|m4 -B 8192|m4|g' \
		${WRKSRC}/crypto/des/Makefile

do-configure:
	cd ${WRKSRC} && ${SETENV} PERL="${PERL}" CROSS_COMPILE="${PKGNAMEPREFIX}" \
	./Configure mingw --prefix="${CONFIGURE_PREFIX}" --install_prefix=${STAGEDIR} \
	--openssldir="${OPENSSLDIR}"

.include <bsd.port.mk>
