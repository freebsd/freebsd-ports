# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	openssl
PORTVERSION=	1.0.2d
PORTREVISION=	1
CATEGORIES=	devel security
MASTER_SITES=	http://www.openssl.org/source/ \
		ftp://ftp.openssl.org/source/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/openssl/source/
PKGNAMEPREFIX=	mingw32-
DIST_SUBDIR=	${DISTNAME}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	The OpenSSL library cross-compiled for MinGW32

BUILD_DEPENDS=	makedepend:devel/makedepend \
		${PKGNAMEPREFIX}gcc:devel/${PKGNAMEPREFIX}gcc \
		${LOCALBASE}/mingw32/include/stdlib.h:devel/${PKGNAMEPREFIX}bin-msvcrt \
		${LOCALBASE}/mingw32/lib/libz.a:devel/mingw32-zlib

USES=		perl5 shebangfix
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
