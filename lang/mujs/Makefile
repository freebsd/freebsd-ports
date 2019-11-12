# $FreeBSD$

PORTNAME=	mujs
DISTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	lang devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	d9a1f4c57f976eeb67d877101fcdca89ecc047ed.patch:-p1 # Enable readline on FreeBSD

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embeddable Javascript interpreter in C

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gmake readline # c11 is induced by the FreeBSD headers via isnan(3), etc, otherwise the project is all c99 code
USE_GITHUB=	yes
GH_ACCOUNT=	ccxvii
USE_LDCONFIG=	yes
ALL_TARGET=	shared static
INSTALL_TARGET=	install-shared install-static

.if defined(WITH_DEBUG) # this project manages its build options itself
MAKE_ARGS=	build=debug
.endif

PLIST_FILES=	bin/mujs \
		include/mujs.h \
		lib/libmujs.so \
		lib/libmujs.a \
		libdata/pkgconfig/mujs.pc

post-install: # https://github.com/ccxvii/mujs/issues/99
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmujs.so

.include <bsd.port.mk>
