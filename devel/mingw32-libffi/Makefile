# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	libffi
PORTVERSION=	3.0.12
CATEGORIES=	devel
MASTER_SITES=	ftp://sourceware.org/pub/libffi/
PKGNAMEPREFIX=	mingw32-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	The libffi library cross-compiled for MinGW32

BUILD_DEPENDS=	${PKGNAMEPREFIX}gcc:${PORTSDIR}/devel/${PKGNAMEPREFIX}gcc \
		${LOCALBASE}/mingw32/include/stdlib.h:${PORTSDIR}/devel/${PKGNAMEPREFIX}bin-msvcrt

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/mingw32
CONFIGURE_ARGS=	--host="mingw32" --enable-shared
CC=		${PKGNAMEPREFIX}gcc
CFLAGS=		-O2	# Override CFLAGS for a cross-build
PLIST_SUB=	PORTVERSION=${PORTVERSION}

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's,^INFO_DEPS[ \t]*=,#&,' \
	                 -e '/^SUBDIRS[ \t]*=/s, man$$,,' \
	                 ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} \
		${PREFIX}/mingw32/lib/libffi-${PORTVERSION}/include/*.h \
		${PREFIX}/mingw32/include/

.include <bsd.port.mk>
